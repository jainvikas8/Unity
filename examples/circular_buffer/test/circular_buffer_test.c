#include "unity_fixture.h"
#include "circular_buffer.h"

TEST_GROUP(CIRCULAR_BUFFER);

TEST_SETUP(CIRCULAR_BUFFER)
{

}

TEST_TEAR_DOWN(CIRCULAR_BUFFER)
{

}

//Init test - number of available data is zero, size of buffer (maximum number of entries)
TEST(CIRCULAR_BUFFER, init_buffer_test_pointer)
{
    uint16_t *buff = circular_buffer_init();

    TEST_ASSERT_NOT_NULL(buff);

    TEST_ASSERT_EQUAL_HEX16(0, *buff);
}
