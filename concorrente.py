#!/usr/bin/python
# -*- coding: utf-8 -*-
 
import threading
from multiprocessing import Process
from threading import Lock
lock = Lock()
import time, numpy
 
matrix_a = None
matrix_b = None
matrix_c = None 

class ThreadMatrix(threading.Thread):
    """ Metodo para criar e matar as threads que serão usadas no cálculo da multiplicação de matrizes e representarão cada linha da matriz final.
    
    """ 
    def __init__(self, id, name):
        threading.Thread.__init__(self)
        self.id = id
        self.name = name 

    def run(self): 
        global matrix_c 

        vector_a = matrix_a[:,[self.id]] # matrix_a[i][self.id] # for i in range(len(matrix_a))]
        vector_b = matrix_b[self.id]# [j] for j in range(len(matrix_b[self.id]))] 

        for i in range(0, len(matrix_a)):
            for j in range(0, len(matrix_b)):
                sum_ = vector_a[i] * vector_b[j] 
                #lock.acquire()
               # time.sleep(1)
                matrix_c[i][j] += sum_
                #lock.release()
	 
  
def conc_mult(matrix_A, matrix_B):
    """ Metodo para efetuar a multiplicação entre duas matrizes de forma concorrente.
    
    @param matrix_A: matriz A que será multiplicada pela B.
    @param matrix_B: matriz B que será multiplicada pela A.

    @return matrix_c: matriz resultante da multiplicação dos dois parâmetros de entrada
    """ 
    global matrix_c_aux, matrix_a, matrix_b, matrix_c
    size = len(matrix_A)

    matrix_a = matrix_A
    matrix_b = matrix_B
    matrix_c = numpy.zeros(shape=(size,size)) 

    threads = []
    for thread in range(size):
    	t = ThreadMatrix(thread, "thread %d" % (thread))
    	threads.append(t)
        t.start() 
    
    return matrix_c     
