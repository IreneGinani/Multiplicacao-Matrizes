import sys 

def leitura(texto_matriz, matriz):
	
	matriz_vetor = []
	contador = 0

	for linha in texto_matriz:
		if (contador > 0):
			contador_interno = 0 
			
			for elem in linha:

				if ((contador_interno+1 < len(linha)) and (linha[contador_interno+1] != " ")):
					if ((elem != " ") and (elem != '\n')):
						matriz_vetor.append(int(elem+linha[contador_interno+1]))
				elif ((elem != " ") and (elem != '\n') and (linha[contador_interno+1] == " ") and (linha[contador_interno-1] == " ")):
					matriz_vetor.append(int(elem))

				contador_interno += 1

		if (len(matriz_vetor) > 0):
			matriz.append(matriz_vetor)
			matriz_vetor = []
		
		contador += 1

if __name__ == "__main__":

	param = sys.argv [1:]
	primeira_matriz = param[0]
	segunda_matriz = param[1]

	arquivo_matriz_1 = open(primeira_matriz, 'r')
	arquivo_matriz_2 = open(segunda_matriz, 'r')

	texto_matriz_1 = arquivo_matriz_1.readlines()
	texto_matriz_2 = arquivo_matriz_2.readlines()

	matriz_1 = []
	matriz_2 = []

	leitura(texto_matriz_1, matriz_1)
	leitura(texto_matriz_2, matriz_2)

	for linha in matriz_2:
		print(linha)


	




