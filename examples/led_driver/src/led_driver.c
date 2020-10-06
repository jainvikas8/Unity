#include "led_driver.h"

static uint16_t *led_address;
enum 
{
    ALL_LEDS_ON = ~0,
    ALL_LEDS_OFF = ~ALL_LEDS_ON
};

void led_driver_create(uint16_t *address)
{
    led_address = address;
    *led_address = ALL_LEDS_OFF;
}

void led_driver_destroy(void)
{

}

static uint16_t led_convert_to_bit(uint16_t number)
{
    return (1 << (number - 1));
}

void led_driver_turn_on(uint16_t number)
{
    *led_address |= led_convert_to_bit(number);
}

void led_driver_turn_off(uint16_t number)
{
    *led_address &= ~led_convert_to_bit(number);;
}

void led_driver_turn_on_all(void)
{
    *led_address = ALL_LEDS_ON;
}
