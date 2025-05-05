#include "matrix.h"

int main(void) {
    int data1[] = {
        1, 2, 3,
        4, 5, 6
    };

    int data2[] = {
        7, 8,
        9, 10,
        11, 12,
    };

    matrix *m1 = create_matrix_from_array(2, 3, data1, 6);
    matrix *m2 = create_matrix_from_array(3, 2, data2, 6);

    if (!m1 || !m2) {
        fprintf(stderr, "Failed to create matrices.\n");
        return 1;
    }

    printf("Matrix 1:\n");
    print_matrix(m1);

    printf("Matrix 2:\n");
    print_matrix(m2);

    matrix *m3 = dot_prod(m1, m2);
    
    printf("Matrix Result:\n");
    print_matrix(m3);


    matrix_destructor(m1);
    matrix_destructor(m2);
    matrix_destructor(m3);

    return 0;
}
