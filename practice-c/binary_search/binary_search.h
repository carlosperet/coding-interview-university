#include <stdlib.h>
#include <stdio.h>

#ifndef PROJECT_BINARY_SEARCH
#define PROJECT_BINARY_SEARCH
typedef struct IntArray {
	int *array;
	size_t length;
} int_array;

int_array *constructor_int_array(int *array, size_t length);

void destructor_int_array(int_array *array);

size_t binary_search(int value, int_array *array);

size_t binary_search_recur(int value, int_array *array, size_t left, size_t right) ;
// Takes an array and the boundaries where you are searching and returns the middle value
size_t get_middle_point(int_array* array, size_t min_idx, size_t max_idx, int *value);

#endif // PROJECT_BINARY_SEARCH
