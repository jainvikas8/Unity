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

TEST(LED_DRIVER, turn_on_multiple_leds)
{
    led_driver_turn_on(9);
    led_driver_turn_on(8);

    TEST_ASSERT_EQUAL_HEX16(0x180, virtual_leds);
}

TEST(LED_DRIVER, turn_all_leds)
{
    led_driver_turn_on_all();

    TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtual_leds);
}

TEST(LED_DRIVER, turn_off_any_led)
{
    led_driver_turn_on_all();
    led_driver_turn_off(8);

    TEST_ASSERT_EQUAL_HEX16(0xFF7F, virtual_leds);
}
