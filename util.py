#!/usr/bin/env python
# -*- coding: utf-8 -*-

import pickle

def read(dimensao):
	""" Metodo para ler arquivos das matrizes para serem multiplicadas.
    
    @param dimensao: dimensão das matrizes para serem lidas.

    @return mA: matriz A
    @return mB: matriz B 
    """ 
	matriz_vetor = []
	contador = 0

	matrix_a_path = "Matrizes/A{0}x{0}.txt".format(dimensao)
	matrix_b_path = "Matrizes/B{0}x{0}.txt".format(dimensao)

	matrix_a_file = open(matrix_a_path, 'r')
	matrix_b_file = open(matrix_b_path, 'r')

	matrix_a = matrix_a_file.readlines()[1:]
	matrix_b = matrix_b_file.readlines()[1:]

	mA = [map(int, l.strip('\n').strip(' ').split(' ')) for l in matrix_a]
	mB = [map(int, l.strip('\n').strip(' ').split(' ')) for l in matrix_b]
	return mA, mB

	
def write(flag, matrix): 
	file_name = 'output/{0}/C{1}x{1}.txt'.format(flag, len(matrix))
	file = open(file_name, 'wb')
	[file.write(" ".join(map(str, line)) + "\n") for line in matrix] 




