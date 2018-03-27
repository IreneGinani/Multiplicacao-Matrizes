#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import argparse
import time

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
		time_total = 0
		time_max = -1
		time_min = float("inf")

		for e in range(0, 2):
			mA, mB = read(d) 
			d = d * 2
			
			for i in xrange(0,5):
			
				start = time.time()
				seq_mult(mA, mB)
				time_inst = time.time() - start
				
				if (time_inst <= time_min):
					time_min = time_inst
				if (time_inst >= time_max):
					time_max = time_inst
				
				time_total += time_inst

			time_m = time_total/20
			print(str(time_m) + "s na matriz de ordem "+ str(d))
			print("Maior tempo de execução foi: "+str(time_max))
			print("Menor tempo de execução foi: "+str(time_min))

		#write('C', conc_mult(mA, mB))
	else:
		error = []
		if args.dimensao % 2 != 0 or args.dimensao < 4 or args.dimensao > 1024:
			error.append("ERROR: valor %s inválido para dimensão" % args.dimensao)
			 
		if not args.dimensao:
			error.append("ERROR: é necessário valor para dimensão")
			 
		if not args.algoritmo:
			error.append("ERROR: é necessário identificar o algoritmo") 

		if error: 
			for e in error: print e
			sys.exit(1)

		mA, mB = read(args.dimensao) 

		if args.algoritmo == 'S':
			write('S', seq_mult(mA, mB))
		elif args.algoritmo == 'C':
			write('C', conc_mult(mA, mB))  

if __name__ == "__main__":
   main(sys.argv[1:])