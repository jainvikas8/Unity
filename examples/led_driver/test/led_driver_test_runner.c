#include "unity_fixture.h"

TEST_GROUP_RUNNER(LED_DRIVER)
{
    RUN_TEST_CASE(LED_DRIVER, leds_off_after_create_run);

    RUN_TEST_CASE(LED_DRIVER, turn_on_led_one);
    RUN_TEST_CASE(LED_DRIVER, turn_off_led_one);

    RUN_TEST_CASE(LED_DRIVER, turn_on_multiple_leds);

    RUN_TEST_CASE(LED_DRIVER, turn_on_all_leds);
    RUN_TEST_CASE(LED_DRIVER, turn_off_any_led);

    RUN_TEST_CASE(LED_DRIVER, led_memory_is_not_readable);
}