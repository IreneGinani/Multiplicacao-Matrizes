void multiply(int dim, int** matrix_r, int** matrixA, int** matrixB) {
    int result;
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            for (int k = 0; k < dim; ++k) {
                const float e1 = matrixA[i][k];
                const float e2 = matrixB[k][j];
                result += e1 * e2;
            }
            matrix_r[i][j] = result;
            result = 0;
        }
    }
}