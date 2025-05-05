#include "tests.h"
#include <assert.h>
#include <stdio.h>

void run_all_tests(void) {
	//invalid_constructor_input();
	not_in_array();
	found_in_array();
	more_tests();
}

void invalid_constructor_input(void) {
	int integers[] = {0};
	int_array *array = constructor_int_array(integers, 0);
	assert(array == NULL);
	destructor_int_array(array);
}

void not_in_array(void) {
	int integers[] = {5, 7, 10, 11, 24, 32, 68, 99, 110};
	int_array *array = constructor_int_array(integers, 9);
	
	size_t index = binary_search(8, array);
	assert(index == (size_t)-1);
	destructor_int_array(array);
}
void found_in_array(void) {
	int integers[] = {5, 7, 10, 11, 24, 32, 68, 99, 110};
	int_array *array = constructor_int_array(integers, 9);

	size_t index = binary_search(10, array);
	assert(index == 2);
	destructor_int_array(array);
}

void more_tests(void) {
	int_array *a;

    int test1[] = {0, 12, 23, 53, 66, 81, 244, 1244, 9929, 10121};
    a = constructor_int_array(test1, 10);
    assert(binary_search(23, a) == 2);
    assert(binary_search(0, a) == 0);
    assert(binary_search(10121, a) == 9);
    assert(binary_search(155, a) == (size_t)-1);
    assert(binary_search(-1, a) == (size_t)-1);
    assert(binary_search(10122, a) == (size_t)-1);
    destructor_int_array(a);

    int test2[] = {0, 1};
    a = constructor_int_array(test2, 2);
    assert(binary_search(0, a) == 0);
    assert(binary_search(1, a) == 1);
    assert(binary_search(2, a) == (size_t)-1);
    destructor_int_array(a);

    int test3[] = {123};
    a = constructor_int_array(test3, 1);
    assert(binary_search(123, a) == 0);
    assert(binary_search(1, a) == (size_t)-1);
    destructor_int_array(a);

    int test4[] = {12, 34, 56};
    a = constructor_int_array(test4, 3);
    assert(binary_search(12, a) == 0);
    assert(binary_search(34, a) == 1);
    assert(binary_search(56, a) == 2);
    assert(binary_search(999, a) == (size_t)-1);
    destructor_int_array(a);

    int test5[] = {12, 34, 56, 78, 90};
    a = constructor_int_array(test5, 5);
    assert(binary_search(12, a) == 0);
    assert(binary_search(34, a) == 1);
    assert(binary_search(56, a) == 2);
    assert(binary_search(78, a) == 3);
    assert(binary_search(90, a) == 4);
    assert(binary_search(999, a) == (size_t)-1);
    destructor_int_array(a);

    // Recursive version
    int test6[] = {0, 12, 23, 53, 66, 81, 244, 1244, 9929, 10121};
    a = constructor_int_array(test6, 10);
    assert(binary_search_recur(23, a, 0, a->length - 1) == 2);
    assert(binary_search_recur(0, a, 0, a->length - 1) == 0);
    assert(binary_search_recur(10121, a, 0, a->length - 1) == 9);
    assert(binary_search_recur(155, a, 0, a->length - 1) == (size_t)-1);
    destructor_int_array(a);

    int test7[] = {0, 1};
    a = constructor_int_array(test7, 2);
    assert(binary_search_recur(0, a, 0, a->length - 1) == 0);
    assert(binary_search_recur(1, a, 0, a->length - 1) == 1);
    assert(binary_search_recur(-1, a, 0, a->length - 1) == (size_t)-1);
    destructor_int_array(a);

    int test8[] = {123};
    a = constructor_int_array(test8, 1);
    assert(binary_search_recur(123, a, 0, a->length - 1) == 0);
    assert(binary_search_recur(1, a, 0, a->length - 1) == (size_t)-1);
    destructor_int_array(a);

    int test9[] = {12, 34, 56};
    a = constructor_int_array(test9, 3);
    assert(binary_search_recur(12, a, 0, a->length - 1) == 0);
    assert(binary_search_recur(34, a, 0, a->length - 1) == 1);
    assert(binary_search_recur(56, a, 0, a->length - 1) == 2);
    assert(binary_search_recur(999, a, 0, a->length - 1) == (size_t)-1);
    destructor_int_array(a);

    int test10[] = {12, 34, 56, 78, 90};
    a = constructor_int_array(test10, 5);
    assert(binary_search_recur(12, a, 0, a->length - 1) == 0);
    assert(binary_search_recur(78, a, 0, a->length - 1) == 3);
    assert(binary_search_recur(90, a, 0, a->length - 1) == 4);
    assert(binary_search_recur(0, a, 0, a->length - 1) == (size_t)-1);
    destructor_int_array(a);
}
