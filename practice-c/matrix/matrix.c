#include "matrix.h"

// It does not check if the array passed is from the stated size, is the job of the programer to do it properly
// Array must be valid and have length of size
i_vector *i_vector_constructor(const int *array, size_t size) {
	// Check if the input is OK
	if (size == 0 || array == NULL) return NULL;

	i_vector *new_i_vector = (i_vector *)malloc(sizeof(i_vector));
	if (!new_i_vector) {
		fprintf(stderr, "Error: The memory asked could not be allocated.\n");
		return NULL;
	}
	// we use calloc to ensure the array in the vector has the stated size
	// if not done it could lead to unexpected behavior later on the code
	new_i_vector->array = (int *)calloc(size, sizeof(int));
	if (!new_i_vector->array) {
		free(new_i_vector);
		fprintf(stderr, "Error: Could not allocate memory for vector array.\n");
		return NULL;
	}

	memcpy(new_i_vector->array, array, size * sizeof(int));

	new_i_vector->size = size;
	return new_i_vector;
}

void i_vector_destructor(i_vector *vector) {
	if (!vector) return;
	free(vector->array);
	free(vector);
}

matrix *create_matrix_from_array(size_t rows, size_t cols, const int *data, size_t data_len) {
    if (!data || rows == 0 || cols == 0 || data_len != rows * cols) {
        fprintf(stderr, "Error: Invalid data pointer, zero dimensions or  data length mismatch.\n");
        return NULL;
    }

    // Check for overflow before calculating size
    if (rows > SIZE_MAX / cols) {
        fprintf(stderr, "Error: Matrix dimensions too large, would cause overflow.\n");
        return NULL;
    }

    size_t size = rows * cols;

    i_vector *vec = malloc(sizeof(i_vector));
    if (!vec) {
        fprintf(stderr, "Error: Could not allocate memory for vector struct.\n");
        return NULL;
    }

    vec->array = calloc(size, sizeof(int));
    if (!vec->array) {
        fprintf(stderr, "Error: Could not allocate memory for array.\n");
        free(vec);
        return NULL;
    }

    memcpy(vec->array, data, data_len * sizeof(int));
    vec->size = size;

    matrix *mat = matrix_constructor(rows, cols, vec);
    if (!mat) {
        i_vector_destructor(vec);  // Clean up if matrix creation failed
        return NULL;
    }

    return mat;
}


matrix *matrix_constructor(size_t rows, size_t columns, i_vector *vector) {
    if (rows == 0 || columns == 0 || !vector || !vector->array) {
        fprintf(stderr, "Error: Invalid rows, columns, or null vector/array.\n");
        return NULL;
    }

    // Overflow protection for rows * columns
    if (rows > SIZE_MAX / columns) {
        fprintf(stderr, "Error: Matrix dimensions too large, multiplication would overflow.\n");
        return NULL;
    }

    size_t expected_size = rows * columns;

    // Ensure vector size matches exactly the matrix dimensions
    if (vector->size != expected_size) {
        fprintf(stderr, "Error: Vector size (%zu) does not match matrix dimensions (%zu x %zu = %zu).\n",
                vector->size, rows, columns, expected_size);
        return NULL;
    }

    matrix *new_matrix = malloc(sizeof(matrix));
    if (!new_matrix) {
        fprintf(stderr, "Error: Could not allocate memory for matrix.\n");
        return NULL;
    }

    new_matrix->rows = rows;
    new_matrix->columns = columns;
    new_matrix->vector = vector;
    return new_matrix;
}

void matrix_destructor(matrix *nmatrix) {
	// Check for input and if input is weird
	if (!nmatrix) return;
	i_vector_destructor(nmatrix->vector);
	free(nmatrix);
}

void print_matrix(const matrix *mat) {
	if (!mat || !mat->vector) return;

	for (size_t i = 0; i < mat->rows; i++) {
		for (size_t j = 0; j < mat->columns; j++) {
			if (j == 0) {
				fprintf(stdout, "\t");
			}
			fprintf(stdout, "%d ", mat->vector->array[i * mat->columns + j]);
		}
		fprintf(stdout, "\n");
	}
	fprintf(stdout, "\n");
}

matrix *dot_prod(matrix *mat1, matrix *mat2) {
    if (!mat1 || !mat2 || mat1->columns != mat2->rows) return NULL;
    int *result = (int *)calloc(mat1->rows * mat2->columns, sizeof(int));
    if (!result) {
        fprintf(stderr, "Error: Failed to allocate memory for dot product result.\n");
        return NULL;
    }

    for (size_t i = 0; i < mat1->rows; i++) {
	for (size_t j = 0; j < mat2->columns; j++) {
	    int sum = 0;
	    for (size_t k = 0; k < mat1->columns; k++) {
		sum += mat1->vector->array[i * mat1->columns + k] * mat2->vector->array[k * mat2->columns + j];
	    }
	    result[i*mat2->columns + j] = sum;
	}
    }

    return create_matrix_from_array(mat1->rows, mat2->columns, result, mat1->rows * mat2->columns);
    free(result);
}
