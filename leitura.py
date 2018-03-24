import sys 
param = sys.argv [1:]
primeira_matriz = param[0]
segunda_matriz = param[1]

arquivo_matriz_1 = open(primeira_matriz, 'r')
arquivo_matriz_2 = open(segunda_matriz, 'r')

matriz_vetor = []
matriz_1 = [[]]
texto_matriz_1 = arquivo_matriz_1.readlines()
contador = 0

for linha in texto_matriz_1:
	if (contador > 0):
		contador_interno = 0 
		
		for elem in linha:

			if ((contador_interno+1 < len(linha)) and (linha[contador_interno+1] != " ")):
				if ((elem != " ") and (elem != '\n')):
					matriz_vetor.append(int(elem+linha[contador_interno+1]))
					elem = linha[contador+1]
			elif ((elem != " ") and (elem != '\n')):
				matriz_vetor.append(elem)
				print ("fui")
			
			contador_interno += 1

	matriz_1.append(matriz_vetor)
	
	contador += 1

for linha in matriz_1:
	for elem in linha:
		print (elem)






texto_matriz_2 = arquivo_matriz_2.readlines()

