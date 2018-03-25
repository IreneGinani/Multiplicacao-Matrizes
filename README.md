# Multiplicação de Matrizes

Projeto de programação concorrente, desenvolvido para verificar se é válido o senso comum de que programas concorrentes apresentam um melhor desempenho com relação a tempo de execução quando comparados a suas respectivas versões sequenciais. 

A metodologia seguida para a demonstração foi:

1. implementação das **versões sequencial e concorrente** do algotimos de multiplicação de matrizes
2. realização de **testes** para diferentes cargas (workloads)
3. **análise dos resultados** em termos de tempo de execução registrado em cada um dos testes
4. **confirmar a validade ou invalidade da hipốtese** inicialmente dada.


### Sequêncial


Para compreendermos a lógica do algoritmo, seguimos o seguinte pseudocodigo:

```
matrix A
matrix B
matrix C # resultado

para i = 1...linha de A
	para j = 1...coluna de B
		soma = 0
		para k = 1...coluna de A
			soma += A[i, k] * B[k, j]
		C[i, j] = soma
```

Então se temos a matriz:
```
matrix_A = [[69, 17], [37, 54]] 

matrix_B =   [[32, 80], [73, 53]]
```

Teremos as seguintes operações para a formação da matriz resultante:

```
C[0,0] = A[0,0] * B[0,0] + A[0,1] * B[1,0]
C[0,1] = A[0,0] * B[0,1] + A[0,1] * B[1,1]
C[1,0] = A[1,0] * B[0,0] + A[1,1] * B[1,0]
C[1,1] = A[1,0] * B[0,1] + A[1,1] * B[1,1]
```


### Concorrênte


```
A[0,0] A[0,2]
A[1,0] A[1,1]

B[0,0] B[0,1]
B[1,0] B[1,1]

C[0,0] C[0,1]
C[1,0] C[1,1]

Task 0 > C[0,0] = A[0,0] * B[0,0] + A[0,1] * B[1,0]
Task 1 > C[0,1] = A[0,0] * B[0,1] + A[0,1] * B[1,1]
Task 3 > C[1,0] = A[1,0] * B[0,0] + A[1,1] * B[1,0]
Task 4 > C[1,1] = A[1,0] * B[0,1] + A[1,1] * B[1,1]
```

### Leitura e execução


