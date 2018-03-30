#ifndef MATRIX_STRUCT
#define MATRIX_STRUCT
#pragma once

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