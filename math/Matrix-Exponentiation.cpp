/**
 * > Author: TISparta
 * > Date: 19-02-19
 *
 * MATRIX EXPONENTIATION
 *
 * Legend
 *
 * > A: A Matrix
 * > m: Dimension of the matrix
 * > b: Exponent
 *
 * Complexity:
 *
 * > pow: O(m ^ 3 log b)
 *
 * Usage:
 *
 * > pow(A, b)
 * - Computes A ^ b
 *
 */

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

typedef long long ll;

inline ll add (const ll& a, const ll& b) { return (a + b) % MOD; }
inline ll mul (const ll& a, const ll& b) { return (a * b) % MOD; }

struct Matrix {
  int n;
  vector <vector <ll>> M;
  Matrix () {};
  Matrix (int n): n(n), M(vector <vector <ll>> (n, vector <ll> (n, 0))) {}
  void identity () { for (int i = 0; i < n; i++) M[i][i] = 1; }
  void print () {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) cout << M[i][j] << ' ';
      cout << endl;
    }
  }
};

Matrix operator * (const Matrix& A, const Matrix& B) {
  Matrix ret(A.n);
  for (int i = 0; i < A.n; i++) {
    for (int j = 0; j < A.n; j++) {
      ll ret_i = 0LL;
      for (int k = 0; k < A.n; k++) ret_i = add(ret_i, mul(A.M[i][k], B.M[k][j]));
      ret.M[i][j] = ret_i;
    }
  }
  return ret;
}

Matrix pow (Matrix A, ll b) {
  Matrix ret(A.n);
  ret.identity();
  while (b) {
    if (b bitand 1) ret = ret * A;
    A = A * A;
    b >>= 1;
  }
  return ret;
}
