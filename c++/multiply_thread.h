#ifndef MULTIPLY_THREADING
#define MULTIPLY_THREADING
#pragma once

#include "matrix_struct.h"

void multiply_threading(matrix& matrix_r, int row, int col, const matrix& matrix_a, const matrix& matrix_b)
{ 
    int r = 0;
    for (int i = 0; i < matrix_r.dimension; ++i) {  
        const int a = matrix_a.data[row][i];
        const int b = matrix_b.data[i][col];
        r += a * b; 
    }
    matrix_r.data[row][col] = r; 
}

void multiply_threading2(matrix& matrix_r, int* vector_a, int* vector_b)
{ 
    //int r = 0;
    for (int i = 0; i < matrix_r.dimension; ++i) {  
    	for (int j = 0; j < matrix_r.dimension; ++j) {  
	    	int sum = vector_a[i] * vector_b[j];
		    matrix_r.data[i][j] += sum;
		}
    } 

    /*for (int i = 0; i < threads_number; ++i)
        cout << "b " << matrix_b.data[t][i] << endl;
         
    for (int i = 0; i < threads_number; ++i)
        cout << "a " << *(matrix_a.data + t)[i] << endl;*/
}

#endif 