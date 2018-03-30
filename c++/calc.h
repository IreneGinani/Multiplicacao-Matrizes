#include <math.h>

float var(float* times, int size, float media) {
	float res = 0;
	for (int i = 0; i < size; ++i) {
		res += (times[i]-media)*(times[i]-media);
	}
	return res/size;
}

float desv(float* times, int size, float media) {
	float desvio = sqrt(var(times, size, media));
	return desvio;
}

