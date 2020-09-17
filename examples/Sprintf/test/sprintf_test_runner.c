#include "unity_fixture.h"

TEST_GROUP_RUNNER(sprintf)
{
    RUN_TEST_CASE(sprintf, No_Format_Oprations);
    RUN_TEST_CASE(sprintf, Insert_string);
}
