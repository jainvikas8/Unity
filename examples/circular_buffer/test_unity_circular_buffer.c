#include "unity_fixture.h"

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST_GROUP(CIRCULAR_BUFFER);

    return UNITY_END();
}
