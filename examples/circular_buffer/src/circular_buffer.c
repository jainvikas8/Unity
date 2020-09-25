#include "circular_buffer.h"
#include <string.h>

#define MAX_BUFF_SIZE 10

static uint16_t buff[MAX_BUFF_SIZE];
uint16_t *write_ptr = NULL;
uint16_t *read_ptr = NULL;
uint16_t *start_ptr = NULL;
uint16_t *end_ptr = NULL;
uint16_t num_available_elements = 0;

uint16_t* circular_buffer_init(void)
{
    read_ptr = write_ptr = start_ptr = &buff[0];
    end_ptr = &buff[MAX_BUFF_SIZE - 1];
    num_available_elements = 0;

    memset(buff, 0x00, sizeof(buff));

    return write_ptr;
}

uint16_t circular_buffer_get_max_size(void)
{
    return MAX_BUFF_SIZE;
}

uint8_t circular_buffer_push_element(uint16_t data)
{
    if(num_available_elements < MAX_BUFF_SIZE)
    {
        *write_ptr++ = data;
        ++num_available_elements;

        if(write_ptr > end_ptr)
            write_ptr = start_ptr;

        return 0;
    }

    return 1;
}

uint16_t circular_buffer_num_available_elements(void)
{
    return num_available_elements;
}

uint16_t* circular_buffer_pop_element(void)
{
    uint16_t *data = NULL;

    if(num_available_elements)
    {
        --num_available_elements;
        data = read_ptr++;

        if(read_ptr > end_ptr)
            read_ptr = start_ptr;
    }

    return data;
}
