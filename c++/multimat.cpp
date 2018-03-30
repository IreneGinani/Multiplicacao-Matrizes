#include <string>
#include <sstream>
#include <iostream>
#include <thread>
// time execution
#include <time.h>
// atoi
#include <cstdlib>

#include "util.h"
#include "multiply.h"
#include "calc.h"
#include "multiply_thread.h"
#include "matrix.h"

using namespace std;

int main(int argc, char* argv[])
{   
    if (argc > 2) {
        int dim = atoi(argv[1]);
        char algorithm = *argv[2];

        stringstream file_matrix_A;
        file_matrix_A << "../Matrizes/A" << dim << "x" << dim << ".txt";
        stringstream file_matrix_B;
        file_matrix_B << "../Matrizes/B" << dim << "x" << dim << ".txt";

        Matrix mA = {}

        int ** matrix_A = new int*[dim];
        int ** matrix_B = new int*[dim];
        int ** matrix_r = new int*[dim];
     
        for (int i = 0; i < dim; ++i) {
            matrix_A[i] = new int[dim];
            matrix_B[i] = new int[dim];
            matrix_r[i] = new int[dim];
            for (int j = 0; j < dim; ++j) {
                matrix_A[i][j] = 0;
                matrix_B[i][j] = 0;
                matrix_r[i][j] = 0;
            }
        }

        read(dim, matrix_A, file_matrix_A.str());
        read(dim, matrix_B, file_matrix_B.str());

        if (algorithm == 'S') {
            clock_t tStart = clock();
            multiply(dim, matrix_r, matrix_A, matrix_B); 
            printf("Time taken: %.6fs\n", (float)(clock() - tStart)/CLOCKS_PER_SEC);
        } else {
            int threads_number = dim * dim;
            thread threads[threads_number];
            clock_t tStart = clock();

            for (int i = 0; i < dim; ++i) { 
                for (int j = 0; j < dim; ++j) { 
                    printf("%s\n", "OKKK");
                    threads[i] = thread(printSomeValues, dim, matrix_r, i, j, matrix_A, matrix_B);
                }
            }

            for (int i = 0; i < threads_number; ++i) { 
                printf("%s\n", "OKKK 2");
                threads[i].join();
            }
            printf("Time taken: %.6fs\n", (float)(clock() - tStart)/CLOCKS_PER_SEC);
        }

        stringstream file_output;
        file_output << "output/" << algorithm << dim << "x" << dim << ".txt";
        write(dim, matrix_r, file_output.str());
    } else {
        int dim = 4;
        int n_matrizes = 10;
        int n_experimentos = atoi(argv[1]);
        float * times = new float[n_experimentos];
        for (int i = 0; i < n_experimentos; ++i) {
            times[i] = 0;
        }

        for (int i = 0; i < n_matrizes; ++i) {
            float total_time = 0;
            float time_min = 100;
            float time_max = -1;
            for (int i = 0; i < n_experimentos; ++i) { 
                stringstream file_matrix_A;
                file_matrix_A << "../Matrizes/A" << dim << "x" << dim << ".txt";
                stringstream file_matrix_B;
                file_matrix_B << "../Matrizes/B" << dim << "x" << dim << ".txt";

                int ** matrix_A = new int*[dim];
                int ** matrix_B = new int*[dim];
                int ** matrix_r = new int*[dim];
             
                for (int i = 0; i < dim; ++i) {
                    matrix_A[i] = new int[dim];
                    matrix_B[i] = new int[dim];
                    matrix_r[i] = new int[dim];
                    for (int j = 0; j < dim; ++j) {
                        matrix_A[i][j] = 0;
                        matrix_B[i][j] = 0;
                        matrix_r[i][j] = 0;
                    }
                }

                read(dim, matrix_A, file_matrix_A.str());
                read(dim, matrix_B, file_matrix_B.str());

                clock_t tStart = clock();
                multiply(dim, matrix_r, matrix_A, matrix_B); 
                float tEnd = (float)(clock() - tStart)/CLOCKS_PER_SEC;

                if (tEnd < time_min) {
                    time_min = tEnd; 
                }
                if (tEnd > time_max) {
                    time_max = tEnd;
                }

                times[i] = tEnd;
                total_time += tEnd;
            }
 
            printf("Time total to matrix %dx%d: %.6fs\n", dim, dim, total_time);
            printf("Time min to matrix %dx%d: %.6fs\n", dim, dim, time_min);
            printf("Time max to matrix %dx%d: %.6fs\n", dim, dim, time_max);

            float time_m = total_time/n_experimentos; 
            printf("Time medio %dx%d: %.6fs\n", dim, dim, time_m);

            float desvio = desv(times, n_experimentos, time_m);
            printf("Desvio Padrão %dx%d: %.6fs\n", dim, dim, desvio);

            printf("----------\n");
            dim = dim * 2;
        }
    }
}
