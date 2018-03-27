# Multiplicação de Matrizes

Projeto de programação concorrente, desenvolvido para verificar se é válido o senso comum de que programas concorrentes apresentam um melhor desempenho com relação a tempo de execução quando comparados a suas respectivas versões sequenciais. 

A metodologia seguida para a demonstração foi:

1. implementação das **versões sequencial e concorrente** do algotimos de multiplicação de matrizes
2. realização de **testes** para diferentes cargas (workloads)
3. **análise dos resultados** em termos de tempo de execução registrado em cada um dos testes
4. **confirmar a validade ou invalidade da hipótese** inicialmente dada.


### Sequêncial

Para compreendermos a lógica do algoritmo, seguimos o seguinte pseudocódigo:
**PS: neste pseudocódigo decidimos começar pelo índice 1.**

```python
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

No pseudocódigo temos a multiplicação dos valores das linhas de A, pelos valores das colunas de B. Então se temos a matriz:
```python
A = [[69, 17], [37, 54]] 

B = [[32, 80], [73, 53]]
```

Teremos as seguintes operações para a formação da matriz resultante (seguindo o pseudo código que apresentamos acima):

```python
C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0] = 69 * 32 + 17 * 73 = 3449
C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1] = 69 * 80 + 17 * 53 = 6421
C[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0] = 37 * 32 + 54 * 73 = 5126
C[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1] = 37 * 80 + 54 * 53 = 5822
```

Compreendido o processo sequencial, vamos ao concorrente.


### Concorrente

Não é muito simples compreender o processo concorrente. Mas nos voltar para o sequêncial talvez nos ajude. 
Tinhamos algumas abordagens possíveis para o problema, como criar uma thread para cada posição da matriz resultante, onde cada uma multiplicaria linha por coluna para aquela respectiva posição.

Então se temos a matriz A e B como abaixo, teremos as Threads executando as respectivas tasks:
```python
A[0,0] A[0,2]
A[1,0] A[1,1]

B[0,0] B[0,1]
B[1,0] B[1,1]

C[0,0] C[0,1]
C[1,0] C[1,1]

Task 0 > C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0]
Task 1 > C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1]
Task 3 > C[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0]
Task 4 > C[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1]
```
Nessa abordagem temos complexidade `N^2`, com `N` sendo o número de linhas, que é igual ao  colunas (matriz quadrada). Isso por que vamos precisar executar uma task para cada posição da nossa matriz.

A abordagem que optamos adotar tem complexidade `N`. Isso por que o número de threads criadas é igual ao número de linhas (ou de colunas), isso foi possível por que cada thread calculava parcela da operação de cada posição. 

``` python
# vector A = [matrix_a[i][id_task] for i in range(len(matrix_a))]
# vector B = [matrix_b[id_task][j] for j in range(len(matrix_b[id_task]))]

vector A = matrix_a[0][0], matrix_a[1][0]
vector B = matrix_b[0][0], matrix_a[0][1]
Task 0 > C[0,0] = A[0,0] * B[0,0] 
         C[0,1] = A[0,0] * B[0,1]
         C[1,0] = A[1,0] * B[0,0] 
         C[1,1] = A[1,0] * B[0,1]

vector A = matrix_a[0][1], matrix_a[1][1]
vector B = matrix_b[1][0], matrix_a[1][1]
Task 1 > C[0,0] = A[0,1] * B[1,0]
         C[0,1] = A[0,1] * B[1,1]
         C[1,0] = A[1,1] * B[1,0]
         C[1,1] = A[1,1] * B[1,1]
```

### Execução

Para conferir como o programa deve ser executado, roda `python multimat.py --help` ou `python multimat.py -h`.

```
$ python multimat.py -h    
usage: multimat.py [-h] [--dimensao N] [--algoritmo S|C] [--experimento N]

Realiza a multiplicação de duas matrizes quadradas.

optional arguments:
  -h, --help       show this help message and exit
  --dimensao N     Número inteiro que representa a dimensão das matrizes
                   quadradas que serão tratadas pelo programa. Valores
                   deverão ser de potências de base 2.
  --algoritmo S|C  Os caracteres S e C indicam respectivamente que será
                   utilizada a solução sequencial ou a solução
                   concorrente.
  --experimento N  Flag para realizar o experimento com todas as matrizes.
```

Como vemos na saida do comando, é possivel usar alguns argumentos no comando. Para identificar a dimensão das matrizes que você deseja fazer a multiplação, use o argumento `--dimensao N`, com `N` sendo o valor da dimensão (**ps**: lembrando que a dimensão deve ser potência de base 2, até a dimensão 1024).
Para identificar o algoritmo que você gostaria de usar, o argumento deve ser `--algoritmo S|C`, com S ou C sendo os identificadores para o algoritmo Sequencial ou Concorrente, respectivamente. Por fim, para rodar o experimento com todas as matrizes, use o argumento `--experimento N`.

A saida das matrizes estará na pasta `output/`, caso o código processado seja sequêncial, estará em `output/S/`, caso seja concorrente estará em `output/C/`.
