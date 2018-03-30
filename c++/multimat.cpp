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
#include "matrix_struct.h"
#include "multiply_thread.h"

using namespace std;


int main(int argc, char* argv[])
{   
    if (argc > 2) {
        int dim = atoi(argv[1]);
        char algorithm = *argv[2];

        stringstream file_matrix_a;
        file_matrix_a << "../Matrizes/A" << dim << "x" << dim << ".txt";
        stringstream file_matrix_b;
        file_matrix_b << "../Matrizes/B" << dim << "x" << dim << ".txt";

        matrix matrix_a;
        matrix_a.dimension = dim;
        matrix_a.initialize();  

        matrix matrix_b;
        matrix_b.dimension = dim;
        matrix_b.initialize();  

        matrix matrix_r;
        matrix_r.dimension = dim;
        matrix_r.initialize(); 
  
        read(matrix_a, file_matrix_a.str()); 
        read(matrix_b, file_matrix_b.str()); 

        if (algorithm == 'S') {
            clock_t tStart = clock();
            multiply(matrix_r, matrix_a, matrix_b); 
            printf("Time taken: %.6fs\n", (float)(clock() - tStart)/CLOCKS_PER_SEC);
        } else {
            int threads_number = dim * dim;
            std::thread threads[threads_number];

            clock_t tStart = clock();

            int row = 0;
            for (int col = 0; col < threads_number; ++col) {  
                threads[col] = std::thread(multiply_threading, ref(matrix_r), row, col%dim, ref(matrix_a), ref(matrix_b));
                if ((col+1) % dim == 0 && col != 0)
                    row += 1;
            } 
            for (int i = 0; i < threads_number; ++i) { 
                threads[i].join();
            }
            printf("Time taken: %.6fs\n", (float)(clock() - tStart)/CLOCKS_PER_SEC);
        }

        stringstream file_output;
        file_output << "output/" << algorithm << "/C" << dim << "x" << dim << ".txt";
        write(matrix_r, file_output.str());
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
                stringstream file_matrix_a;
                file_matrix_a << "../Matrizes/A" << dim << "x" << dim << ".txt";
                stringstream file_matrix_b;
                file_matrix_b << "../Matrizes/B" << dim << "x" << dim << ".txt";
 
                matrix matrix_a, matrix_b, matrix_r;
                matrix_a.dimension = dim;
                matrix_a.initialize(); 
 
                matrix_b.dimension = dim;
                matrix_b.initialize(); 
 
                matrix_r.dimension = dim;
                matrix_r.initialize(); 
          
                read(matrix_a, file_matrix_a.str());
                read(matrix_b, file_matrix_b.str());

                clock_t tStart = clock();
                multiply(matrix_r, matrix_a, matrix_b); 
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
