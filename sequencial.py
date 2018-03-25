#!/usr/bin/env python
# -*- coding: utf-8 -*-

import time

def seq_mult(matrix_A, matrix_B): 
	start = int(round(time.time() * 1000))

	size = len(matrix_A)  

	matrix_C = [[0 for x in range(size)] for y in range(size)] 
	
	for i in range(0, size):
		for j in range(0, size):
			soma = 0
			for k in range(0, size):  
				soma += matrix_A[i][k] * matrix_B[k][j]
			matrix_C[i][j] = soma 

	print("Execution Time --->", (int(round(time.time() * 1000)) - start))

	return matrix_C