#include "unity_fixture.h"

TEST_GROUP_RUNNER(CIRCULAR_BUFFER)
{
    RUN_TEST_CASE(CIRCULAR_BUFFER, init_buffer_test_pointer);
    RUN_TEST_CASE(CIRCULAR_BUFFER, init_buffer_test_buff_max_size_not_zero);

    RUN_TEST_CASE(CIRCULAR_BUFFER, init_buffer_test_empty_first_element);
    RUN_TEST_CASE(CIRCULAR_BUFFER, init_buffer_test_empty_all_elements);

    RUN_TEST_CASE(CIRCULAR_BUFFER, push_buffer_one_element);
    RUN_TEST_CASE(CIRCULAR_BUFFER, push_buffer_all_elements);
    RUN_TEST_CASE(CIRCULAR_BUFFER, push_buffer_overflow_elements);

    RUN_TEST_CASE(CIRCULAR_BUFFER, buffer_num_elements_present);
    RUN_TEST_CASE(CIRCULAR_BUFFER, buffer_num_elements_present_after_adding_one);
    RUN_TEST_CASE(CIRCULAR_BUFFER, buffer_num_elements_present_after_adding_few);
    RUN_TEST_CASE(CIRCULAR_BUFFER, buffer_num_elements_present_after_adding_all);
    RUN_TEST_CASE(CIRCULAR_BUFFER, buffer_num_elements_present_every_iteration);

    RUN_TEST_CASE(CIRCULAR_BUFFER, buffer_read_one_on_empty_buffer);
    RUN_TEST_CASE(CIRCULAR_BUFFER, buffer_read_one_on_empty_buffer_check_num_elements);
    RUN_TEST_CASE(CIRCULAR_BUFFER, buffer_read_one_and_compare);
    RUN_TEST_CASE(CIRCULAR_BUFFER, buffer_num_elements_present_after_reading_one);
    RUN_TEST_CASE(CIRCULAR_BUFFER, buffer_read_all_and_compare_check_num_elements);
}
