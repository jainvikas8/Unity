#include "led_driver.h"

static uint16_t *led_address;
static uint16_t led_image;
enum 
{
    ALL_LEDS_ON = ~0,
    ALL_LEDS_OFF = ~ALL_LEDS_ON
};

static void update_hardware(void)
{
    *led_address = led_image;
}

static uint16_t led_convert_to_bit(uint16_t number)
{
    return (1 << (number - 1));
}

void led_driver_create(uint16_t *address)
{
    led_address = address;
    led_image = ALL_LEDS_OFF;
    update_hardware();
}

void led_driver_destroy(void)
{

}

void led_driver_turn_on(uint16_t number)
{
    if(number == 0 || number > 16)
        return;

    led_image |= led_convert_to_bit(number);
    update_hardware();
}

void led_driver_turn_off(uint16_t number)
{
    led_image &= ~led_convert_to_bit(number);
    update_hardware();
}

void led_driver_turn_on_all(void)
{
    led_image = ALL_LEDS_ON;
    update_hardware();
}
