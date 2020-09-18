#include "unity_fixture.h"
#include "led_driver.h"

TEST_GROUP(LED_DRIVER);

static uint16_t virtual_leds = 0xFFFF;

TEST_SETUP(LED_DRIVER)
{
    led_driver_create(&virtual_leds);
}

TEST_TEAR_DOWN(LED_DRIVER)
{

}

TEST(LED_DRIVER, leds_off_after_create_run)
{
    TEST_ASSERT_EQUAL_HEX16(0, virtual_leds);
}

TEST(LED_DRIVER, turn_on_led_one)
{
    led_driver_turn_on(1);

    TEST_ASSERT_EQUAL_HEX16(1, virtual_leds);
}

TEST(LED_DRIVER, turn_off_led_one)
{
    led_driver_turn_on(1);
    led_driver_turn_off(1);

    TEST_ASSERT_EQUAL_HEX16(0, virtual_leds);
}