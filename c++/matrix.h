struct Matrix {
  int ** data; 
  int dimension;

  void initialize() {
    data = new int*[dimension];
    for (int i = 0; i < dimension; ++i) {
      data[i] = new int[dimension];
      for (int j = 0; j < dimension; ++j) {
        data[i][j] = 0;
      }
    }
  }
};