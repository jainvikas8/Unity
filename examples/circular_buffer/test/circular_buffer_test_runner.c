#include "unity_fixture.h"

TEST_GROUP_RUNNER(CIRCULAR_BUFFER)
{
    RUN_TEST_CASE(CIRCULAR_BUFFER, init_buffer_test_pointer);
    RUN_TEST_CASE(CIRCULAR_BUFFER, init_buffer_test_size_max);

    RUN_TEST_CASE(CIRCULAR_BUFFER, init_buffer_test_empty_first_element);
    RUN_TEST_CASE(CIRCULAR_BUFFER, init_buffer_test_empty_all_elements);
}
