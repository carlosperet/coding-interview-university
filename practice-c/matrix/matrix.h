#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

#ifndef SIZE_MAX
#define SIZE_MAX ((size_t) -1)
#endif

#ifndef PROJECT_MATRIX
#define PROJECT_MATRIX

typedef struct IVector {
	size_t size;
	int* array;
} i_vector;

typedef struct Matrix {
	size_t rows;
	size_t columns;
	i_vector *vector;
} matrix;

// Constructs an i_vector by copying the input array into newly allocated memory.
i_vector *i_vector_constructor(const int *array, size_t size);

// Frees memory associated with an i_vector.
void i_vector_destructor(i_vector *vector);

// Constructs a matrix from given dimensions and an existing i_vector.
matrix *matrix_constructor(size_t rows, size_t columns, i_vector *vector);

// Frees memory associated with a matrix, including its internal vector.
void matrix_destructor(matrix *nmatrix);

// Constructs a matrix from a raw array of integers, allocating the backing vector internally.
matrix *create_matrix_from_array(size_t rows, size_t cols, const int *data, size_t data_len);
//matrix *create_matrix_from_array(size_t rows, size_t cols, const int *data);

// Prints the matrix into the command line
void print_matrix(const matrix *mat);

// Dot product between two matrices
matrix *dot_prod(matrix *mat1, matrix *mat2);

#endif // PROJECT_MATRIX
