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
    RUN_TEST_CASE(LED_DRIVER, check_upper_and_lower_bounds);
    RUN_TEST_CASE(LED_DRIVER, check_out_of_bounds_when_turning_on);
    RUN_TEST_CASE(LED_DRIVER, check_out_of_bounds_when_turning_off);

    RUN_TEST_CASE(LED_DRIVER, out_of_bounds_runtime_error);

    RUN_TEST_CASE(LED_DRIVER, out_of_bounds_todo);
}