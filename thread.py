#!/usr/bin/python
 
import threading
import time

matrix_a = [[69, 17], 
			[37, 54]] 

matrix_b =   [[32, 80], 
			  [73, 53]]

matrix_b_t = [[32, 73], 
			  [80, 53]]

matrix_c = [[0, 0], 
			[0, 0]]
 
#69 * 32 + 17 * 73, 69 * 80 + 17 * 53
#37 * 32 + 54 * 73, 37 * 80 + 54 * 53

#0,0 * 0,0 + 0,1 * 0,1 ; 0,0 * 0,1 + 0,1 * 1,1

#

linha1 * coluna1 + linha1 * coluna2

class ThreadMatrix(threading.Thread):
    def __init__(self, id, name, v1, v2):
        threading.Thread.__init__(self)
        self.id = id
        self.name = name
        self.v1 = v1
        self.v2 = v2

    def run(self): 
    	print "runing " + self.name + "\n"
    	sum = 0
    	for index in range(0, len(matrix_a)): 
    		sum += (self.v1[index] * self.v2[index])
		print sum
		time.sleep(1)
	
 
start = int(round(time.time() * 1000))

matrix_b = [list(i) for i in zip(*matrix_b)] 

threads = len(matrix_c) * len(matrix_c)
print "%d threads... " % threads

for thread in range(threads):
	t = ThreadMatrix(thread, "thread %d" % (thread), matrix_a[thread], matrix_b[thread])
	t.start() 
	t.join()

print("Execution Time --->", (int(round(time.time() * 1000)) - start))

print(matrix_c)