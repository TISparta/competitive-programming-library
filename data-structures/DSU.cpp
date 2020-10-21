struct DSU {
  vi root;
  
  DSU (int n) {
    root.resize(n);
    iota(all(n));
  }

  int get (int u) {
    return root[u] = (u == root[u]) ? u : get(root[u]);
  }

  int join (int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v) return 0;
    if (u < v) swap(u, v);
    root[u] = v;
    return 1;
  }
};
