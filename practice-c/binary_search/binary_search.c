#include "binary_search.h"
#include <stdio.h>

size_t binary_search(int value, int_array *array) {
	if (array == NULL || array->length == 0) {
		fprintf(stderr, "Error: Array is NULL or empty\n");
		return -1;
	}
	size_t min_idx = 0;
	size_t max_idx = array->length - 1;
	int curr_value = 0;

	while (min_idx <= max_idx) {
		size_t middle_idx = get_middle_point(array, min_idx, max_idx, &curr_value);
		if (value == curr_value) {
			return middle_idx;
		} else if(curr_value < value) {
			min_idx = middle_idx+1;
		} else {
			if(max_idx == 0) break;
			max_idx = middle_idx-1;
		}
	}

	return -1;
}


size_t binary_search_recur(int value, int_array *array, size_t left, size_t right) {
    if (array == NULL || array->length == 0 || left > right) {
        return (size_t)-1;
    }

    size_t mid = left + (right - left) / 2;

    if (array->array[mid] == value) {
        return mid;
    } else if (array->array[mid] > value) {
        if (mid == 0) return (size_t)-1; // avoid underflow
        return binary_search_recur(value, array, left, mid - 1);
    } else {
        return binary_search_recur(value, array, mid + 1, right);
    }
}


size_t get_middle_point(int_array* array, size_t min_idx, size_t max_idx, int *value) {
	size_t idx = (min_idx + max_idx) / 2; // this will truncate but its fine
	*value = array->array[idx];
	return idx;
}

int_array *constructor_int_array(int *array, size_t length) {
	if (!array || length == 0) {
		fprintf(stderr, "Error: Invalid input - array is NULL or length is zero\n");
		return NULL;
	}

	int_array *new_int_array = (int_array*)malloc(sizeof(int_array));
	if (!new_int_array) {
		fprintf(stderr, "Error: Memory could not be allocated\n");
		return NULL;
	}

	int *inner_array = (int *)malloc(sizeof(int) * length);
	if (!inner_array) {
		fprintf(stderr, "Error: Memory could not be allocated\n");
		free(new_int_array);
		return NULL;
	}

	for (size_t i = 0; i < length; i++) {
		inner_array[i] = array[i];
	}

	new_int_array->array = inner_array;
	new_int_array->length = length;
	return new_int_array;
}

void destructor_int_array(int_array *array) {
	if (!array) return;
	
	free(array->array);
	free(array);
}
