std::mutex m;//door handle

void multiply_threading(int** result, const int size, const int row, const int col, const int** matrix_a, const int** matrix_b) {  
  	int r = 0;
  	for (int i = 0; i < size; ++i) {  
      	const int a = matrix_a[row][i];
      	const int b = matrix_b[i][col];
      	r += a * b; 
	}
	result[row][col] = r;
}

void printSomeValues(int dim, int** matrix_r, int row, int col, int** matrix_a, int** matrix_b)
{
	printf("%s\n", "OKKK --");
	int r = 0;
  	for (int i = 0; i < dim; ++i) {  
      	const int a = matrix_a[row][i];
      	const int b = matrix_b[i][col];
      	r += a * b; 
	}
	m.lock();
	matrix_r[row][col] = r;
	m.unlock();
}