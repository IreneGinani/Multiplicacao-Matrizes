#!/usr/bin/env python
# -*- coding: utf-8 -*-


def seq_mult(matrix_A, matrix_B): 
	""" Metodo para efetuar a multiplicação entre duas matrizes de forma sequencial.
    
    @param matrix_A: matriz A que será multiplicada pela B.
    @param matrix_B: matriz B que será multiplicada pela A.

    @return matrix_c: matriz resultante da multiplicação dos dois parâmetros de entrada
    """ 
	size = len(matrix_A)  
	matrix_C = [[0 for x in range(size)] for y in range(size)] 
	
	for i in range(0, size):
		for j in range(0, size):
			soma = 0
			for k in range(0, size):  
				soma += matrix_A[i][k] * matrix_B[k][j]
			matrix_C[i][j] = soma 
	return matrix_C