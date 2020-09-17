#include "unity_fixture.h"

TEST_GROUP_RUNNER(LED_DRIVER)
{
    RUN_TEST_CASE(LED_DRIVER, leds_off_after_create_run);
}