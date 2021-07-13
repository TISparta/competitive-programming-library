struct LCA {
  vector <vi> up;
  vi depth;
  const int LG = 18;

  LCA (const vector <vi>& g, int n, int root) {
    up = vector <vi> (n + 1, vi(LG, -1));
    depth = vi(n + 1);
    
    function <void(int,int)> dfs = [&] (int u, int p) -> void {
      depth[u] = (p == -1) ? 0 : depth[p] + 1;
      for (int bit = 1; bit < LG; bit++) {
        int v = up[u][bit - 1];
        if (v == -1) break;
        up[u][bit] = up[v][bit - 1];
      }
      for (auto v: g[u]) {
        if (v == p) continue;
        up[v][0] = u;
        dfs(v, u);
      }
    };
    
    dfs(root, -1);
  }

  int walk (int u, int k) {
    for (int bit = 0; bit < LG and k; bit++) {
      if ((k >> bit) & 1) {
        u = up[u][bit];
        k -= (1 << bit);
      }
    }
    return u;
  }
  
  int lca (int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    u = walk(u, depth[u] - depth[v]);
    if (u == v) return u;
    for (int bit = LG - 1; bit >= 0; bit--) {
      if (up[u][bit] != up[v][bit]) {
        u = up[u][bit];
        v = up[v][bit];
      }
    }
    return up[u][0];
  }
  
  int dis (int u, int v) {
    int p = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[p];
  }
};

