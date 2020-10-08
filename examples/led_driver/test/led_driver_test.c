#include "unity_fixture.h"
#include "led_driver.h"
#include "Runtime_error_stub.h"

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

TEST(LED_DRIVER, turn_on_all_leds)
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

TEST(LED_DRIVER, led_memory_is_not_readable)
{
    virtual_leds = 0xFFFF;
    led_driver_turn_on(7);

    TEST_ASSERT_EQUAL_HEX16(0x0040, virtual_leds);
}

TEST(LED_DRIVER, check_upper_and_lower_bounds)
{
    led_driver_turn_on(1);
    led_driver_turn_on(16);

    TEST_ASSERT_EQUAL_HEX16(0x8001, virtual_leds);
}

TEST(LED_DRIVER, check_out_of_bounds_when_turning_on)
{
    led_driver_turn_on(0);
    TEST_ASSERT_EQUAL_HEX16(0x0, virtual_leds);

    led_driver_turn_on(17);
    TEST_ASSERT_EQUAL_HEX16(0x0, virtual_leds);

    led_driver_turn_on(33);
    TEST_ASSERT_EQUAL_HEX16(0x0, virtual_leds);

    led_driver_turn_on(3141);
    TEST_ASSERT_EQUAL_HEX16(0x0, virtual_leds);
}

TEST(LED_DRIVER, check_out_of_bounds_when_turning_off)
{
    led_driver_turn_on_all();

    led_driver_turn_off(0);
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtual_leds);

    led_driver_turn_off(17);
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtual_leds);

    led_driver_turn_off(33);
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtual_leds);

    led_driver_turn_off(3141);
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtual_leds);
}

TEST(LED_DRIVER, out_of_bounds_runtime_error)
{
    led_driver_turn_on(0);
    TEST_ASSERT_EQUAL_STRING("LED Driver: out-ofbounds LED", RES_get_last_error());

    TEST_ASSERT_EQUAL(-1, RES_get_last_parameter());
}

IGNORE_TEST(LED_DRIVER, out_of_bounds_todo)
{
    /* TODO: what should we do during runtime */
}

TEST(LED_DRIVER, check_led_is_on)
{
    TEST_ASSERT_FALSE(led_driver_is_on(11));

    led_driver_turn_on(11);

    TEST_ASSERT_TRUE(led_driver_is_on(11));
}
