#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int *array;		// Pointer to array
	size_t size;		// Array filled elements
	size_t capacity;	// Array max capacity
} DynamicArray;

// Initialize dynamic array
void initArray(DynamicArray *arr, size_t initialCapacity) {
	arr->capacity = initialCapacity;
	arr->size = 0;
	arr->array = (int *)malloc(arr->capacity * sizeof(int));
};

void push_back(DynamicArray *arr, int value) {

	if(arr->size >= arr->capacity) {
		// double the capacity
		arr->capacity *= 2;
		int *newArr = (int *)malloc(arr->capacity * sizeof(int));
		int *myarr = arr->array;

		for (size_t i = 0; i < arr->size; i++) {
			*(newArr++) = *(myarr++);
		}
		free(arr->array);
		arr->array = (newArr - arr->size); // would have been easier to use [] instead of pointer arithmetics
	}
	
	if (!arr->array) {
		perror("Failed to resize array\n");
		exit(EXIT_FAILURE);
	}

	arr->array[arr->size++] = value; // Add the new element
};

void push_front(DynamicArray *arr, int value) {
	if (arr->size >= arr->capacity) {
		arr->capacity *= 2;
		int *newArr = (int *)malloc(arr->capacity * sizeof(int));
		int *init = newArr;

		for (size_t i = 0; i < arr->size; i++) {
			*(++newArr) = *arr->array++;
		}

		free(arr->array - arr->size);
		arr->array = init;
		*arr->array = value; // Add the new element
		arr->size++;
		return;
	}

	int *end_1 = (arr->array + arr->size -1);
	int *end = (arr->array + arr->size);
	while (arr->array != end) {
		*(end--) = *(end_1--);
	}

	*arr->array = value; // Add the new element
	arr->size++;
}

void free_array(DynamicArray *arr) {
	free(arr->array);
	arr->array = NULL; // NO dangling pointer
	
	arr->size = arr->capacity = 0;
};

int is_empty(DynamicArray *arr) {
	if (!arr->size) return 1;
	return 0;
};

int at_index(DynamicArray *arr, size_t idx) {
	if (idx >= arr->size) {
		perror("Wrong indexing\n");
		exit(EXIT_FAILURE);
	}
	return *(arr->array + idx);
}

void insert(DynamicArray *arr, size_t idx, int value) {
    // Resize if necessary
    if (idx >= arr->capacity) {
        while (idx >= arr->capacity) {
            arr->capacity *= 2; // Double capacity until it fits
        }
        int *newArr = (int *)realloc(arr->array, arr->capacity * sizeof(int));
        if (!newArr) {
            perror("Failed to resize array");
            exit(EXIT_FAILURE);
        }
        arr->array = newArr;
    }

    // Expand size if inserting beyond the last element
    if (idx >= arr->size) {
        for (size_t i = arr->size; i < idx; i++) {
            arr->array[i] = 0; // Fill gaps with zeros
        }
        arr->array[idx] = value;
        arr->size = idx + 1;
        return;
    }

    // Shift elements to the right to make space
    for (size_t i = arr->size; i > idx; i--) {
        arr->array[i] = arr->array[i - 1];
    }

    // Insert new value
    arr->array[idx] = value;
    arr->size++;
}

int pop(DynamicArray *arr) {
	int temp = arr->array[arr->size - 1];
	arr->array[arr->size - 1] = 0;
	arr->size--;
	return temp;
}

void delete(DynamicArray *arr, size_t idx) {
	if (idx >= arr->size) {
		perror("Wrong indexing\n");
		exit(EXIT_FAILURE);
	}
	for (size_t i = idx; i < arr->size - 1; i++) {
		arr->array[i] = arr->array[i + 1];
	}

	arr->size--; // Reduce size
}

void remove_a(DynamicArray *arr, int value) {
	for (size_t idx = 0; idx <= arr->size; idx++) {
		if (arr->array[idx] == value) {

		}

	}
}

int main() {
	DynamicArray arr;
	initArray(&arr, 4); // Start with capacity of 4

	printf("Is empty? %d\n", is_empty(&arr));
	push_back(&arr, 10);
	push_back(&arr, 20);
	push_back(&arr, 30);
	printf("idx 3 -> %d\n", at_index(&arr, 2));
	printf("idx 3 -> %d\n", at_index(&arr, 0));
	push_back(&arr, 40);
	push_back(&arr, 50); // This will trigger a resize
	push_front(&arr, 01);
	push_back(&arr, 60);
	push_front(&arr, 00);
	push_front(&arr, -1);
	printf("The poped value is %d\n",pop(&arr));

	insert(&arr, 10, 100);
	insert(&arr, 6, 66);
	delete(&arr, 6);

	printf("Is empty? %d\n", is_empty(&arr));

	// Print the elements in the array
	for (size_t i = 0; i < arr.size; i++) {
		printf("%d ", arr.array[i]);
	}
	printf("\n");
	printf("The size of the array is: %lu and its capacity is: %lu\n", arr.size, arr.capacity);
	

	// Clean up
	free_array(&arr);
	return 0;
}
