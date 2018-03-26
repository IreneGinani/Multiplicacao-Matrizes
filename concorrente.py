#!/usr/bin/python
 
import threading
import time
 
matrix_a = None
matrix_b = None
matrix_c = None 

class ThreadMatrix(threading.Thread):
    def __init__(self, id, name):
        threading.Thread.__init__(self)
        self.id = id
        self.name = name 

    def run(self): 
        global layers, matrix_c
    	print "Starting " + self.name + "\n"

        vector_a = [matrix_a[i][self.id] for i in range(len(matrix_a))]
        vector_b = [matrix_b[self.id][j] for j in range(len(matrix_b[self.id]))]
        matrix_c_aux = [[0 for x in range(len(matrix_a))] for y in range(len(matrix_a))]

        for i in range(0, len(matrix_a)):
            for j in range(0, len(matrix_b)):
                matrix_c_aux[i][j] = vector_a[i] * vector_b[j] 
                matrix_c[i][j] += matrix_c_aux[i][j]

        print "End " + self.name + "\n"
	
  
def conc_mult(matrix_A, matrix_B):
    global matrix_c_aux, matrix_a, matrix_b, matrix_c
    size = len(matrix_A)

    matrix_a = matrix_A
    matrix_b = matrix_B
    matrix_c = [[0 for x in range(size)] for y in range(size)]

    threads = []
    for thread in range(size):
    	t = ThreadMatrix(thread, "thread %d" % (thread))
    	threads.append(t)
        t.start()
    
    for t in threads: t.join()
    
    return matrix_c     