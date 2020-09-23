#include "circular_buffer.h"
#include <string.h>

#define MAX_BUFF_SIZE 10

static uint16_t buff[MAX_BUFF_SIZE];

uint16_t* circular_buffer_init(void)
{
    uint16_t *ptr = &buff[0];

    memset(buff, 0x00, sizeof(buff));

    return ptr;
}

uint16_t circular_buffer_get_max_size(void)
{
    return MAX_BUFF_SIZE;
}
