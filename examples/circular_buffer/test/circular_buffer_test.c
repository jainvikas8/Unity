#include "unity_fixture.h"
#include "circular_buffer.h"

TEST_GROUP(CIRCULAR_BUFFER);

TEST_SETUP(CIRCULAR_BUFFER)
{

}

TEST_TEAR_DOWN(CIRCULAR_BUFFER)
{

}

TEST(CIRCULAR_BUFFER, init_buffer_test_pointer)
{
    uint16_t *buff = circular_buffer_init();

    TEST_ASSERT_NOT_NULL(buff);
}

TEST(CIRCULAR_BUFFER, init_buffer_test_size_max)
{
    TEST_ASSERT_NOT_EQUAL_HEX16(0, circular_buffer_get_max_size());
}

TEST(CIRCULAR_BUFFER, init_buffer_test_empty_first_element)
{
    uint16_t *buff = circular_buffer_init();

    TEST_ASSERT_EQUAL_HEX16(0, *buff);
}

TEST(CIRCULAR_BUFFER, init_buffer_test_empty_all_elements)
{
    uint16_t *buff = circular_buffer_init();
    uint16_t size = circular_buffer_get_max_size();

    for (uint16_t index = 0 ; index < size ; index++)
    {
        TEST_ASSERT_EQUAL_HEX16(0, *buff);
        buff++;
    }
}
