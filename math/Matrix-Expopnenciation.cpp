struct Matrix {
  int n;
  vector <vi> mat;
  Matrix () {};
  Matrix (int n): n(n), mat(vector <vi> (n, vi (n, 0))) {}

  void identity () { 
    for (int i = 0; i < n; i++) mat[i][i] = 1;
  }

  void print () {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << mat[i][j] << " \n"[i == n - 1];
      }
    }
  }

  friend Matrix operator * (const Matrix& A, const Matrix& B) {
    Matrix ret(A.n);
    for (int i = 0; i < A.n; i++) {
      for (int j = 0; j < A.n; j++) {
        int ret_i = 0;
        for (int k = 0; k < A.n; k++) {
          ret_i = NT::add(ret_i, NT::mul(A.mat[i][k], B.mat[k][j]));
        }
        ret.mat[i][j] = ret_i;
      }
    }
    return ret;
  }

  static Matrix bin_pow (Matrix A, ll b) {
    Matrix ret(A.n);
    ret.identity();
    while (b) {
      if (b & 1) ret = ret * A;
      A = A * A;
      b >>= 1;
    }
    return ret;
  }

  const int operator () (int r, int c) const {
    return mat[r][c];
  }

  int& operator () (int r, int c) {
    return mat[r][c];
  }

};
