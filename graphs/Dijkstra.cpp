/**
 * > Author: TISparta
 * > Date: 23-09-18
 *
 * DIJKSTRA
 *
 * Legend:
 *
 * > V: Vertices
 * > E: Edges
 *
 * Complexity:
 *
 * > Dijkstra: O(E log V)
 *
 * Usage:
 * > Dijkstra(s, dis)
 * - Sets dis[u] = Distance(s, u) for all u in V
 *
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_V = 5e4 + 10;
const ll INF = 1e15;

vector <int> G[MAX_V];
vector <ll> W[MAX_V];

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
