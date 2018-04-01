#ifndef UTIL
#define UTIL
#pragma once

#include <fstream>
#include <string>
#include "matrix_struct.h"

using namespace std;

/**
    Método que faz a leitura de um arquivos correspondente a uma matriz.
    - m: matriz que será lida
    - file: arquivo que deve ser lido
**/
void read(matrix m, string file) {
    ifstream f(file); 

    string str; 
    getline(f, str);

    for (int i = 0; i < m.dimension; i++)
        for (int j = 0; j < m.dimension; j++) 
            f >> m.data[i][j];

    f.close();
} 

/**
    Método que faz a escrita em um arquivos correspondente a uma matriz.
    - m: matriz que será lida
    - file: arquivo que deve ser lido
**/
void write(matrix matrix, string file) {
    ofstream output(file); 

    for (int i = 0; i < matrix.dimension; i++) {
        for (int j = 0; j < matrix.dimension; j++) {
            output << matrix.data[i][j] << " ";
        }
        output << endl;
    }
    output.close();
}  

/**
    Imprime uma dada matriz.
    - m: matriz que deve ser impressa.
**/
void print(matrix m) {
    cout << endl;
    for (int i = 0; i < m.dimension; ++i) { 
        for (int j = 0; j < m.dimension; ++j) {
            cout << m.data[i][j] << "   ";
        }
        cout << "" << endl;
    }
}

#endif