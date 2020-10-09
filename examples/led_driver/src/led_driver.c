#include "led_driver.h"

static uint16_t *led_address;
static uint16_t led_image;
enum 
{
    ALL_LEDS_ON = ~0,
    ALL_LEDS_OFF = ~ALL_LEDS_ON
};
enum
{
    FIRST_LED = 1,
    LAST_LED = 16
};

static void update_hardware(void)
{
    *led_address = led_image;
}

static uint16_t led_convert_to_bit(uint16_t number)
{
    return (1 << (number - 1));
}

static bool led_check_boundary(uint16_t number)
{
    if(number >= FIRST_LED && number <= LAST_LED)
        return false;

    return true;
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
    if(led_check_boundary(number) > 0)
        return;

    led_image |= led_convert_to_bit(number);
    update_hardware();
}

void led_driver_turn_off(uint16_t number)
{
    if(led_check_boundary(number) > 0)
        return;
    
    led_image &= ~led_convert_to_bit(number);
    update_hardware();
}

void led_driver_turn_on_all(void)
{
    led_image = ALL_LEDS_ON;
    update_hardware();
}

bool led_driver_is_on(uint16_t number)
{
    if(led_check_boundary(number) > 0)
        return false;

    return (led_image & led_convert_to_bit(number));
}

bool led_driver_is_off(uint16_t number)
{
    return !(led_driver_is_on(number));
}
