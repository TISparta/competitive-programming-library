struct DSU {
  vi root;
  vi ss;
  int n_sets;

  DSU (int n): n_sets(n) {
    root.resize(n);
    iota(all(root), 0);
    ss = vi(n, 1);
  }

  int get (int u) {
    return root[u] = (u == root[u]) ? u : get(root[u]);
  }

  int join (int u, int v) {
    u = get(u);
    v = get(v);
    if (u == v) return 0;
    if (ss[u] < ss[v]) swap(u, v);
    root[v] = u;
    ss[u] += ss[v];
    n_sets -= 1;
    return 1;
  }
};
