#ifndef MATRIX_STRUCT
#define MATRIX_STRUCT
#pragma once

/**
	Estrutura da matrix.
	initialize(): metodo para inicializar uma matrix de uma dada dimensão com valores 0.
**/
typedef struct Matrix_Struct {
  int ** data; 
  int dimension;

	void initialize() {
	    data = new int*[dimension];
	    for (int i = 0; i < dimension; ++i) {
		    data[i] = new int[dimension];
		      	for (int j = 0; j < dimension; ++j) {
		        	data[i][j] = 0;
		    	}
	    }
	}
} matrix;

#endif