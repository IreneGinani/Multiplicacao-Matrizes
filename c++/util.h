#include <fstream>
#include <string>

using namespace std;

void read(int dim, int** matrix, string file) {
    ifstream f(file); 

    string str; 
    getline(f, str);

    for (int i = 0; i < dim; i++)
        for (int j = 0; j < dim; j++) 
            f >> matrix[i][j];

    f.close();
} 

void write(int dim, int** matrix, string file) {
    ofstream output(file); 

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            output << matrix[i][j] << " ";
        }
        output << endl;
    }
    output.close();
}  

void print(int dim, int** matrix) {
    cout << endl;
    for (int i = 0; i < dim; ++i) { 
        for (int j = 0; j < dim; ++j) {
            cout << matrix[i][j] << "   ";
        }
        cout << "" << endl;
    }
}