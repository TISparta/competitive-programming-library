/**
 * > Author: TISparta
 * > Date: 05-09-19
 *
 * ARTICULATION POINTS
 *
 * Legend:
 *
 * > V: Number of vertices
 * > G: Tree adyacency list
 *
 * Complexity:
 *
 * > articulationPoints: O(V + E)
 *
 * Usage:
 * > articulationPoints ()
 * - Find the articulation points
 *
 */


#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

vector <int> G[N];

void articulationPoints () {
  vector <int> tin(N, -1);
  vector <int> low(N, -1);
  int timer = 0;
  function <void(int,int)> dfs = [&] (int u, int p) {
    tin[u] = low[u] = timer++;
    int children = 0;
    bool is_ap = false;
    for (int v: G[u]) {
      if (v == p) continue;
      if (tin[v] != -1) {
        low[u] = min(low[u], tin[v]);
      } else {
        children++;
        dfs(v, u);
        low[u] = min(low[u], low[v]);
        if (p != -1 and tin[u] <= low[v]) {
          is_ap = true;
        }
      }
    }
    if (p == -1 and children > 1) {
      is_ap = true;
    }
    if (is_ap) {
      // DO SOMETHING
    }
  };
  dfs(1, -1);
}
