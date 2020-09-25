#include "unity_fixture.h"
#include "circular_buffer.h"

static uint16_t *buff_ptr = NULL,
                buff_size = 0,
                dummy_data;

TEST_GROUP(CIRCULAR_BUFFER);

TEST_SETUP(CIRCULAR_BUFFER)
{
    buff_ptr = circular_buffer_init();
    buff_size = circular_buffer_get_max_size();
    dummy_data = 0xffee;
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
    TEST_ASSERT_EQUAL_HEX8(0, circular_buffer_push_element(dummy_data));
}

TEST(CIRCULAR_BUFFER, push_buffer_all_elements)
{
    for (uint16_t index = 0 ; index < buff_size ; index++)
    {
        TEST_ASSERT_EQUAL_HEX8(0, circular_buffer_push_element(dummy_data));
    }
}

TEST(CIRCULAR_BUFFER, push_buffer_overflow_elements)
{
    for (uint16_t index = 0 ; index < buff_size ; index++)
    {
        TEST_ASSERT_EQUAL_HEX8(0, circular_buffer_push_element(dummy_data));
    }

    TEST_ASSERT_NOT_EQUAL_HEX8(0, circular_buffer_push_element(dummy_data));
}

TEST(CIRCULAR_BUFFER, buffer_num_elements_present)
{
    TEST_ASSERT_EQUAL_HEX16(0, circular_buffer_num_available_elements());
}

TEST(CIRCULAR_BUFFER, buffer_num_elements_present_after_adding_one)
{
    circular_buffer_push_element(dummy_data);

    TEST_ASSERT_NOT_EQUAL_HEX16(0, circular_buffer_num_available_elements());
    TEST_ASSERT_EQUAL_HEX16(1, circular_buffer_num_available_elements());
}

TEST(CIRCULAR_BUFFER, buffer_num_elements_present_after_adding_few)
{
    uint16_t index;

    for (index = 0 ; index < (buff_size/2) ; index++)
    {
        circular_buffer_push_element(dummy_data);
    }

    TEST_ASSERT_NOT_EQUAL_HEX16(0, circular_buffer_num_available_elements());
    TEST_ASSERT_EQUAL_HEX16(index, circular_buffer_num_available_elements());
}

TEST(CIRCULAR_BUFFER, buffer_num_elements_present_after_adding_all)
{
    uint16_t index;

    for (index = 0 ; index < buff_size ; index++)
    {
        circular_buffer_push_element(dummy_data);
    }

    TEST_ASSERT_NOT_EQUAL_HEX16(0, circular_buffer_num_available_elements());
    TEST_ASSERT_EQUAL_HEX16(index, circular_buffer_num_available_elements());
}

TEST(CIRCULAR_BUFFER, buffer_num_elements_present_every_iteration)
{
    uint16_t index = 0;

    while (index < buff_size)
    {
        circular_buffer_push_element(dummy_data);

        TEST_ASSERT_NOT_EQUAL_HEX16(0, circular_buffer_num_available_elements());
        TEST_ASSERT_EQUAL_HEX16(++index, circular_buffer_num_available_elements());
    }
}

TEST(CIRCULAR_BUFFER, buffer_read_one_on_empty_buffer)
{
    uint16_t *read_data = 0x0000;

    read_data = circular_buffer_pop_element();

    TEST_ASSERT_NULL(read_data);
}

TEST(CIRCULAR_BUFFER, buffer_read_one_on_empty_buffer_check_num_elements)
{
    circular_buffer_pop_element();

    TEST_ASSERT_EQUAL_HEX16(0, circular_buffer_num_available_elements());
}

TEST(CIRCULAR_BUFFER, buffer_read_one_and_compare)
{
    uint16_t *read_data = NULL;

    circular_buffer_push_element(dummy_data);

    read_data = circular_buffer_pop_element();

    TEST_ASSERT_NOT_NULL(read_data);
    TEST_ASSERT_EQUAL_HEX16(dummy_data, *read_data);
}

TEST(CIRCULAR_BUFFER, buffer_num_elements_present_after_reading_one)
{
    circular_buffer_push_element(dummy_data);
    circular_buffer_pop_element();

    TEST_ASSERT_EQUAL_HEX16(0, circular_buffer_num_available_elements());
}

TEST(CIRCULAR_BUFFER, buffer_read_all_and_compare_check_num_elements)
{
    uint16_t index, *read_data;

    for (index = 0 ; index < buff_size ; index++)
    {
        circular_buffer_push_element(dummy_data);
    }

    for (index = 0 ; index < buff_size ; index++)
    {
        read_data = circular_buffer_pop_element();
        TEST_ASSERT_NOT_NULL(read_data);
        TEST_ASSERT_EQUAL_HEX16(dummy_data, *read_data);
    }

    TEST_ASSERT_EQUAL_HEX16(0, circular_buffer_num_available_elements());
}
