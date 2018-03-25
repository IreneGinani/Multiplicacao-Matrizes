#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import argparse

from reader import read

def main(argv): 
	parser = argparse.ArgumentParser(description='Realiza a multiplicação de duas matrizes quadradas.')
	parser.add_argument('dimensao', 
						metavar='N', 
						type=int,  
	                   	help='Número inteiro que representa a dimensão das matrizes quadradas que serão tratadas pelo programa. Valores deverão ser de potências de base 2.')
	parser.add_argument('algoritmo',
						metavar='S|C',   
	                    help='Os caracteres S e C indicam respectivamente que será utilizada a solução sequencial ou a solução concorrente.') 
	parser.add_argument('--experimento',   
	                    help='Flag para realizar o experimento com todas as matrizes.') 

	args = parser.parse_args() 

	read(args.dimensao)
	#print args.dimensao
	#print args.algoritmo
	#print args.experimento

if __name__ == "__main__":
   main(sys.argv[1:])