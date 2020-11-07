void Dijkstra (int s, vector <ll>& dis) {
  fill(begin(dis), end(dis), INF);
  set <pair <ll, int>> Q;
  dis[s] = 0;
  Q.insert({0LL, s});
  while (not Q.empty()) {
    pair <ll, int> q = *begin(Q);
    int u = q.second;
    Q.erase(begin(Q));
    for (int i = 0; i < int(G[u].size()); i++) {
      int v = G[u][i];
      ll w = W[u][i];
      if (dis[v] > dis[u] + w) {
        Q.erase({dis[v], v});
        dis[v] = dis[u] + w;
        Q.insert({dis[v], v});
      }
    }
  }
}
