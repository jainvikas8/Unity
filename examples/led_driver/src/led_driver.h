#ifndef _LED_DRIVER_H_

    #define _LED_DRIVER_H_

    #include <stdint.h>

    void led_driver_create(uint16_t *address);
    void led_driver_destroy(void);

#endif //_LED_DRIVER_H_