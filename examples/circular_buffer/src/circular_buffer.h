#ifndef _CIRCULAR_BUFFER_H_

    #define _CIRCULAR_BUFFER_H_

    #include <stdint.h>
    #include <stddef.h>

    uint16_t* circular_buffer_init(void);
    uint16_t circular_buffer_get_max_size(void);
    uint8_t circular_buffer_push_element(uint16_t);
    uint16_t circular_buffer_num_available_elements(void);
    uint16_t* circular_buffer_pop_element(void);

#endif //_CIRCULAR_BUFFER_H_
