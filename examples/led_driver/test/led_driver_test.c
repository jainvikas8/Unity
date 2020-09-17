#include "unity_fixture.h"
#include "led_driver.h"

TEST_GROUP(LED_DRIVER);

TEST_SETUP(LED_DRIVER)
{
    
}

TEST_TEAR_DOWN(LED_DRIVER)
{

}

TEST(LED_DRIVER, leds_off_after_create_run)
{
    uint16_t virtual_leds = 0xFFFF;

    led_driver_create(&virtual_leds);

    TEST_ASSERT_EQUAL_HEX16(0, virtual_leds);
}