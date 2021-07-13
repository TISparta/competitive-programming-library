template <typename T = int>
struct STable {
  const int LG = 20;
  vector <vector <T>> st;
  
  inline T op (T x, T y) {
    return min(x, y);
  }

  STable (int l, int r, const vector <T>& arr) {
    st = vector <vector <T>> (r + 1, vector <T> (LG));
    for (int i = l; i <= r; i++) {
      st[i][0] = arr[i];
    }
    for (int bit = 1; bit < LG; bit++) {
      for (int i = l; i + (1 << bit) - 1 <= r; i++) {
        int j = i + (1 << (bit - 1));
        st[i][bit] = op(st[i][bit - 1], st[j][bit - 1]);
      }
    }
  }

  T query (int l, int r) {
    if (l == r) return st[l][0];
    int x = 31 - __builtin_clz(r - l);
    int l2 = r - (1 << x) + 1;
    return op(st[l][x], st[l2][x]);
  }

};
