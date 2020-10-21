struct STree {
  int from, to;
  struct State {
    // TODO
  };
  vector <State> st;
  State NIL; // TODO

  void build (int u, int l, int r, const vi& arr) {
    if (l == r) {
      // TODO
      return;
    }
    int m = (l + r) >> 1;
    int lu = u << 1;
    int ru = lu | 1;
    build(lu, l, m, arr);
    build(ru, m + 1, r, arr);
    st[u] = merge(st[lu], st[ru]);
  }

  STree (int l, int r, const vi& arr): from(l), to(r) {
    st.resize(4 * r);
    build(1, l, r, arr);
  }

  State merge (State lu, State ru) {
    // TODO
  }

  void push (int u, int l, int r) {
    // TODO
  }

  void update (int L, int R, int val, int u, int l, int r) {
    push(u, l, r);
    if (r < L or R < l) return;
    if (L <= l and r <= R) {
      // TODO
      push(u, l, r);
      return;
    }
    int m = (l + r) >> 1;
    int lu = u << 1;
    int ru = lu | 1;
    update(L, R, val, lu, l, m);
    update(L, R, val, ru, m + 1, r);
    st[u] = merge(st[lu], st[ru]);
  }

  void update (int L, int R, int val) { update(L, R, val, 1, from, to); }

  State query (int L, int R, int u, int l, int r) {
    push(u, l, r);
    if (r < L or R < l) return NIL;
    if (L <= l and r <= R) return st[u];
    int m = (l + r) >> 1;
    return merge(query(L, R, (u << 1), l, m), query(L, R, (u << 1) | 1, m + 1, r));
  }

  State query (int L, int R) { return query(L, R, 1, from, to); }

};
