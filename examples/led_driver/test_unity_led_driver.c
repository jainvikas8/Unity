#include "unity_fixture.h"

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST_GROUP(LED_DRIVER);

    return UNITY_END();
}
