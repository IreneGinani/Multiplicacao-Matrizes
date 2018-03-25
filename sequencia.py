"""
matrix A
matrix B
matrix C = resultado

para i = 1...linha de A
	para j = 1...coluna de B
		soma = 0
		para k = 1...coluna de A
			soma += A[i, k] * B[k, j]
		C[i, j] = soma
"""
matrix_A = [[69, 17], 
			[37, 54]] 

matrix_B =   [[32, 80], 
			  [73, 53]]

def mult(): 
	size = len(matrix_A)

	matrix_C = [[0 for x in range(size)] for y in range(size)] 
	soma = 0
	for i in range(0, size):
		for j in range(0, size):
			for k in range(0, size):
				soma += (matrix_A[i, k] * matrix_B[k, j])
			matrix_C[i, j] = soma
	print 

if __name__ == '__main__':
	mult()