#ifndef MULTIPLY_THREADING
#define MULTIPLY_THREADING
#pragma once

#include "matrix_struct.h"

/**
	Método para multiplicar a matrix na versão com threads.
	Esse método recebe a matriz resultando, a linha e coluna da posição que terá seu valor calculado, 
	a matriz A e matriz B.
	Esse método vai gerar ao todo N^2 threads, com N correspondendo ao número de linhas (ou colunas) da tabela.
	- matrix_r: matriz resultante
	- row: linha da posição que terá seu valor calculado
	- col: coluna da posição que terá seu valor calculado
	- matrix_a: matriz A 
	- matrix_b: matriz B
**/
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

/**
	Método para multiplicar a matrix na versão com threads.
	Esse método recebe a matriz resultando, um vetor a (com valores de uma coluna da matriz A, e vetor b, 
	com valores de uma linha da matriz B.
	Esse método vai gerar ao todo N threads, com N correspondendo ao número de linhas (ou colunas) da tabela.
	- matrix_r: matriz resultante 
	- vector_a: vetor com valores de uma coluna da matriz A 
	- vector_b: vetor com valores de uma lina da matriz B
**/
void multiply_threading_(matrix& matrix_r, int* vector_a, int* vector_b)
{  
    for (int i = 0; i < matrix_r.dimension; ++i) {  
    	for (int j = 0; j < matrix_r.dimension; ++j) {  
	    	int sum = vector_a[i] * vector_b[j];
		    matrix_r.data[i][j] += sum;
		}
    }  
}

#endif 