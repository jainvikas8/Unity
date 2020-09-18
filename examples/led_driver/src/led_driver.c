#include "led_driver.h"

static uint16_t *led_address;

void led_driver_create(uint16_t *address)
{
    led_address = address;
    *led_address = 0;
}

void led_driver_destroy(void)
{

}

void led_driver_turn_on(uint16_t number)
{
    *led_address = 1;
}

void led_driver_turn_off(uint16_t number)
{
    *led_address = 0;
}
