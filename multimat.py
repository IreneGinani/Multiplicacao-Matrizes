#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import argparse

from util import read, write
from sequencial import seq_mult
from concorrente import conc_mult

def main(argv): 
	parser = argparse.ArgumentParser(description='Realiza a multiplicação de duas matrizes quadradas.')
	parser.add_argument('--dimensao', 
						metavar='N', 
						type=int,  
	                   	help='Número inteiro que representa a dimensão das matrizes quadradas que serão tratadas pelo programa. Valores deverão ser de potências de base 2.')
	parser.add_argument('--algoritmo',
						metavar='S|C',   
	                    help='Os caracteres S e C indicam respectivamente que será utilizada a solução sequencial ou a solução concorrente.') 
	parser.add_argument('--experimento',
						metavar='N',    
	                    help='Flag para realizar o experimento com todas as matrizes.') 

	args = parser.parse_args() 
	
	if args.experimento:
		d = 4
		for dim in range(0, 10):
			mA, mB = read(d) 
			write(seq_mult(mA, mB))
			d = d * 2
	else:
		mA, mB = read(args.dimensao) 

		if args.algoritmo == 'S':
			write(seq_mult(mA, mB))
		elif args.algoritmo == 'C':
			conc_mult(mA, mB)

if __name__ == "__main__":
   main(sys.argv[1:])