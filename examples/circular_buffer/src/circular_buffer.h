#ifndef _CIRCULAR_BUFFER_H_

    #define _CIRCULAR_BUFFER_H_

    #include <stdint.h>
    #include <stddef.h>

    uint16_t* circular_buffer_init(void);
    uint16_t circular_buffer_get_max_size(void);

#endif //_CIRCULAR_BUFFER_H_
