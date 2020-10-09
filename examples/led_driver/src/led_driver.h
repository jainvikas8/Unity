#ifndef _LED_DRIVER_H_

    #define _LED_DRIVER_H_

    #include <stdint.h>
    #include <stdbool.h>

    void led_driver_create(uint16_t *address);
    void led_driver_destroy(void);
    void led_driver_turn_on(uint16_t led_number);
    void led_driver_turn_off(uint16_t led_number);
    void led_driver_turn_on_all(void);
    bool led_driver_is_on(uint16_t led_number); 
    bool led_driver_is_off(uint16_t led_number); 

#endif //_LED_DRIVER_H_