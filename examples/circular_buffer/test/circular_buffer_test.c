#include "unity_fixture.h"
#include "circular_buffer.h"

static uint16_t *buff_ptr = NULL, buff_size = 0;

TEST_GROUP(CIRCULAR_BUFFER);

TEST_SETUP(CIRCULAR_BUFFER)
{
    buff_ptr = circular_buffer_init();
    buff_size = circular_buffer_get_max_size();
}

TEST_TEAR_DOWN(CIRCULAR_BUFFER)
{
    buff_ptr = NULL;
    buff_size = 0;
}

TEST(CIRCULAR_BUFFER, init_buffer_test_pointer)
{
    TEST_ASSERT_NOT_NULL(buff_ptr);
}

TEST(CIRCULAR_BUFFER, init_buffer_test_buff_max_size_not_zero)
{
    TEST_ASSERT_NOT_EQUAL_HEX16(0, buff_size);
}

TEST(CIRCULAR_BUFFER, init_buffer_test_empty_first_element)
{
    TEST_ASSERT_EQUAL_HEX16(0, *buff_ptr);
}

TEST(CIRCULAR_BUFFER, init_buffer_test_empty_all_elements)
{
    for (uint16_t index = 0 ; index < buff_size ; index++)
    {
        TEST_ASSERT_EQUAL_HEX16(0, *buff_ptr);
        buff_ptr++;
    }
}
