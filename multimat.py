#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import argparse
import time
import math

from util import read, write
from sequencial import seq_mult
from concorrente import conc_mult

def variancia(valores, media):
	""" Metodo para efetuar a variância do conjunto de valores passados como argumento.
    
    @param valores: vetor o qual se deseja obter a variância.
    @param media: media dos valores passados por parâmetro

    @return variancia: variância dos valores
    """ 
	soma = 0
	variancia = 0
	for valor in valores:
		soma += math.pow( (valor - media), 2)
		variancia = soma / float( len(valores) )
		return variancia
 
 
def desvio_padrao(valores, media):
	""" Metodo para efetuar o desvio padrão do conjunto de valores passados como argumento.
    
    @param valores: vetor o qual se deseja obter o desvio padrão.
    @param media: media dos valores passados por parâmetro

    @return desvio_padrao: desvio_padrao dos valores
    """ 
    desvio_padrao = math.sqrt( variancia(valores,media) )
	return desvio_padrao

def main(argv):

	""" Metodo main que executa a ação principal de multiplicar as duas matrizes, a partir da flag dada na linha de comando iremos usar um método diferente para multiplicar.
    
    @param argv: flags que direcionam o calculo da multiplicação (se será sequencial, concorrrente ou o experimento.

    """  
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
		valores = []

		for e in range(0, 10):
			mA, mB = read(d) 
			d = d * 2
			
			for i in xrange(0,20):
			
				start = time.time()
				seq_mult(mA, mB)
				time_inst = time.time() - start
				
				if (time_inst <= time_min):
					time_min = time_inst
				if (time_inst >= time_max):
					time_max = time_inst
				
				time_total += time_inst
				valores.append(time_inst)

			time_m = time_total/20
			print("A média de execução é de: " + str(time_m) + "s na matriz de ordem "+ str(d))
			print("Maior tempo de execução foi: "+str(time_max) + "s")
			print("Menor tempo de execução foi: "+str(time_min) + "s")
			print ("O desvio padrão é de: " + str(desvio_padrao(valores,time_m)) + "s")

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