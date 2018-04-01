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
            int threads_number = dim ;
            std::thread threads[threads_number];

            clock_t tStart = clock();
 
            for (int t = 0; t < threads_number; ++t) { 
                int* va = *(matrix_a.data + t);
                int* vb = matrix_b.data[t];
                threads[t] = std::thread(multiply_threading_, ref(matrix_r), va, vb);
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
            float tEnd = 0;

            for (int alg = 0; alg < 2; ++alg) {
                total_time=0;
                for (int i = 0; i < n_experimentos; ++i) { 
                    if (alg == 0) {
                        clock_t tStart = clock();
                        multiply(matrix_r, matrix_a, matrix_b); 
                        tEnd = (float)(clock() - tStart)/CLOCKS_PER_SEC;
                    } else {
                        int threads_number = dim ;
                        std::thread threads[threads_number];

                        clock_t tStart = clock();
             
                        for (int t = 0; t < threads_number; ++t) { 
                            int* va = *(matrix_a.data + t);
                            int* vb = matrix_b.data[t];
                            threads[t] = std::thread(multiply_threading_, ref(matrix_r), va, vb);
                        } 
                        for (int i = 0; i < threads_number; ++i) { 
                            threads[i].join();
                        }
                        tEnd = (float)(clock() - tStart)/CLOCKS_PER_SEC;
                    }

                    if (tEnd < time_min) {
                        time_min = tEnd; 
                    }
                    if (tEnd > time_max) {
                        time_max = tEnd;
                    }

                    times[i] = tEnd;
                    total_time += tEnd;
                } 
 
                if (alg == 0) { 
                    printf("ALGO: %s\n", "SEQUENCIAL"); 
                } else { 
                    printf("ALGO: %s\n", "CONCORRENTE");
                } 
                printf("Time total to matrix %dx%d: %.6fs\n", dim, dim, total_time);
                printf("Time min to matrix %dx%d: %.6fs\n", dim, dim, time_min);
                printf("Time max to matrix %dx%d: %.6fs\n", dim, dim, time_max);

                float time_m = total_time/n_experimentos; 
                printf("Time medio %dx%d: %.6fs\n", dim, dim, time_m);

                float desvio = desv(times, n_experimentos, time_m);
                printf("Desvio Padrão %dx%d: %.6fs\n", dim, dim, desvio);

                printf("----------\n");
            }
            dim = dim * 2;
        }
    }
}
