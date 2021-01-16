// O(V E^2)
struct FordFulkerson {
  vector <map <int, int>> cap;
  vi prev;

  FordFulkerson (int n) {
    cap.resize(n);
  }

  void add_edge (int u, int v, int w) {
    cap[u][v] += w;
  }

  int bfs (int s, int t) {
    prev = vi(sz(cap), -1);
    queue <pii> q;
    q.push(pii(s, 1e9));
    while (not q.empty()) {
      auto [u, f] = q.front();
      if (u == t) return f;
      q.pop();
      for (auto [v, c]: cap[u]) {
        if (prev[v] == -1 and c > 0) {
          prev[v] = u;
          q.push(pii(v, min(f, c)));
        }
      }
    }
    return 0;
  }

  void update (int s, int t, int f) {
    while (t != s) {
      int p = prev[t];
      cap[p][t] -= f;
      cap[t][p] += f;
      t = p;
    }
  }

  int max_flow (int s, int t) {
    int flow = 0;
    while (true) {
      int nflow = bfs(s, t);
      if (nflow == 0) break;
      flow += nflow;
      update(s, t, nflow);
    }
    return flow;
  }
};
