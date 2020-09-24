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

TEST(CIRCULAR_BUFFER, push_buffer_one_element)
{
    uint16_t data = 0xffee;

    TEST_ASSERT_EQUAL_HEX8(0, circular_buffer_push_element(data));
}

TEST(CIRCULAR_BUFFER, push_buffer_all_elements)
{
    uint16_t data = 0xffee;

    for (uint16_t index = 0 ; index < buff_size ; index++)
    {
        TEST_ASSERT_EQUAL_HEX8(0, circular_buffer_push_element(data));
    }
}

TEST(CIRCULAR_BUFFER, push_buffer_overflow_elements)
{
    uint16_t data = 0xffee;

    for (uint16_t index = 0 ; index < buff_size ; index++)
    {
        TEST_ASSERT_EQUAL_HEX8(0, circular_buffer_push_element(data));
    }

    TEST_ASSERT_NOT_EQUAL_HEX8(0, circular_buffer_push_element(data));
}

TEST(CIRCULAR_BUFFER, buffer_num_elements_present)
{
    TEST_ASSERT_EQUAL_HEX16(0, circular_buffer_num_available_elements());
}

TEST(CIRCULAR_BUFFER, buffer_num_elements_present_after_adding_one)
{
    uint16_t data = 0xffee;

    circular_buffer_push_element(data);

    TEST_ASSERT_NOT_EQUAL_HEX16(0, circular_buffer_num_available_elements());
    TEST_ASSERT_EQUAL_HEX16(1, circular_buffer_num_available_elements());
}

TEST(CIRCULAR_BUFFER, buffer_num_elements_present_after_adding_few)
{
    uint16_t data = 0xffee;
    uint16_t index;

    for (index = 0 ; index < (buff_size/2) ; index++)
    {
        circular_buffer_push_element(data);
    }

    TEST_ASSERT_NOT_EQUAL_HEX16(0, circular_buffer_num_available_elements());
    TEST_ASSERT_EQUAL_HEX16(index, circular_buffer_num_available_elements());
}

TEST(CIRCULAR_BUFFER, buffer_num_elements_present_after_adding_all)
{
    uint16_t data = 0xffee;
    uint16_t index;

    for (index = 0 ; index < buff_size ; index++)
    {
        circular_buffer_push_element(data);
    }

    TEST_ASSERT_NOT_EQUAL_HEX16(0, circular_buffer_num_available_elements());
    TEST_ASSERT_EQUAL_HEX16(index, circular_buffer_num_available_elements());
}
