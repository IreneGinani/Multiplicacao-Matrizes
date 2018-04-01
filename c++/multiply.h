#ifndef MULTIPLY
#define MULTIPLY
#pragma once

#include "matrix_struct.h"

/**
    Método sequencial para calcular a multiplicação de matrizes.
    - matrix_r: matriz resultante
    - matrix_a: matriz A
    - matrix_b: matriz B
**/
void multiply(matrix& matrix_r, matrix& matrix_a, matrix& matrix_b) {
    int result;
    for (int i = 0; i < matrix_r.dimension; ++i) {
        for (int j = 0; j < matrix_r.dimension; ++j) {
            for (int k = 0; k < matrix_r.dimension; ++k) {
                const float e1 = matrix_a.data[i][k];
                const float e2 = matrix_b.data[k][j];
                result += e1 * e2;
            }
            matrix_r.data[i][j] = result;
            result = 0;
        }
    }
}

#endif