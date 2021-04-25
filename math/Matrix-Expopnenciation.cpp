template <class T>
struct Matrix {
  int n;
  vector <vector <T>> mat;
  Matrix () {};
  Matrix (int n): n(n), mat(vector <vector <T>> (n, vector <T> (n, 0))) {}

  void identity () {
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) mat[i][j] = (i == j);
  }

  void print () {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << mat[i][j] << " \n"[j + 1 == n];
      }
    }
  }

  template <class R>
  friend Matrix <R> operator * (const Matrix <R>& A, const Matrix <R>& B) {
    Matrix <R> ret(A.n);
    for (int i = 0; i < A.n; i++) {
      for (int j = 0; j < A.n; j++) {
        R ret_i = 0;
        for (int k = 0; k < A.n; k++) {
          ret_i += A.mat[i][k] * B.mat[k][j];
        }
        ret.mat[i][j] = ret_i;
      }
    }
    return ret;
  }

  template <typename R>
  friend Matrix <R> power (Matrix <R> A, ll b) {
    assert(b >= 0);
    Matrix <R> ret(A.n);
    ret.identity();
    while (b) {
      if (b & 1) ret = ret * A;
      A = A * A;
      b >>= 1;
    }
    return ret;
  }

  vector <T>& operator [] (int r) { return mat[r]; }

};
