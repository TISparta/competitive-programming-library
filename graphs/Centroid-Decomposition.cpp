struct CD {
  vi pa;

  CD (const vector <vi>& g, int n) {
    pa = vi(n + 1);
    vi ss(n + 1);
    vi father(n + 1);
    vector <bool> blocked(n + 1, false);
    
    function <int(int,int,int)> find_centroid = [&] (int u, int p, int n) -> int {
      father[u] = p;
      int c = -1;
      ss[u] = 1;
      int mx = 0;
      for (auto v: g[u]) {
        if (v == p or blocked[v]) continue;
        c = max(c, find_centroid(v, u, n));
        ss[u] += ss[v];
        mx = max(mx, ss[v]);
      }
      mx = max(mx, n - ss[u]);
      if (2 * mx <= n) c = u;
      return c;
    };

    function <void(int,int,int)> decomposition = [&] (int u, int p, int n) -> void {
      int c = find_centroid(u, p, n);
      pa[c] = p;
      blocked[c] = true;
      if (father[c] != -1) ss[father[c]] = n - ss[c];
      for (auto v: g[c]) {
        if (v == p or blocked[v]) continue;
        decomposition(v, c, ss[v]);
      }
    };

    decomposition(1, -1, n);
  }

};
