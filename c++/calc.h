#ifndef CALC
#define CALC
#pragma once

#include <math.h>

/**
	Método que calcula a variância no vetor com os tempos da execução do experimento.
	- times: vetor de tempos das 20 execuções
	- size: tamanho do vetor de tempos (20)
    - media: tempo médio das 20 execuções
**/
float var(float* times, int size, float media) {
	float res = 0;
	for (int i = 0; i < size; ++i) {
		res += (times[i]-media)*(times[i]-media);
	}
	return res/size;
}

/**
	Métido que calcula o desvio padrão dos tempos de execução.
	- times: vetor de tempos das 20 execuções
	- size: tamanho do vetor de tempos (20)
    - media: tempo médio das 20 execuções

**/
float desv(float* times, int size, float media) {
	float desvio = sqrt(var(times, size, media));
	return desvio;
}

#endif