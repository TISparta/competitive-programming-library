struct STable {
  const int LG = 18;
  vector <vi> st;
  
  inline int op (int x, int y) {
    // TODO operation
  }

  STable (int l, int r, const vi& arr) {
    st = vector <vi> (r + 1, vi(LG));
    for (int i = l; i <= r; i++) {
      st[i][0] = arr[i];
    }
    for (int bit = 1; bit < LG; bit++) {
      for (int i = l; i + (1 << bit) <= r; i++) {
        int j = i + (1 << (bit - 1));
        st[i][bit] = op(st[i][bit - 1], st[j][bit - 1]);
      }
    }
  }

  int query (int l, int r) {
    if (l == r) return st[l][0];
    int x = 31 - __builtin_clz(r - l);
    int ll = r - (1 << x) + 1;
    return op(st[l][x], st[ll][x]);
  }

};
