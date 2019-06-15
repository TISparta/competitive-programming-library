/**
 * > Author: TISparta
 * > Date: 05-10-18
 *
 * LOWEST COMMOM ANCESTOR (LCA)
 *
 * Legend:
 *
 * > V: Number of vertices
 * > G: Tree adyacency list
 *
 * Complexity:
 *
 * > preprocess: O(V log V)
 * > getLCA: O(log V)
 *
 * Usage:
 * > preprocess (root)
 * - Run a dfs from root and build a sparse table
 *
 * > getLCA (u, v)
 * - Returns the lowest common ancestor of `u` and `v`
 *
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 1e5, LG = 18;

int V, depth[MAX_V], up[LG][MAX_V];
vector <int> G[MAX_V];

void dfs (int u, int p = -1) {
  for (int bit = 1; bit < LG; bit++) {
    int v = up[bit - 1][u];
    if (v == -1) break;
    up[bit][u] = up[bit - 1][v];
  }
  for (int v: G[u]) {
    if (v != p) {
      depth[v] = depth[u] + 1;
      up[0][v] = u;
      dfs(v, u);
    }
  }
}

int walk (int u, int k) {
  for (int bit = LG - 1; bit >= 0; bit--)
    if ((k >> bit) bitand 1) u = up[bit][u];
  return u;
}

int getLCA (int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  u = walk(u, depth[u] - depth[v]);
  if (u == v) return u;
  for (int bit = LG - 1; bit >= 0; bit--)
    if (up[bit][u] != up[bit][v])
      u = up[bit][u], v = up[bit][v];
  return up[0][u];
}

void preprocess (int root) {
  memset(up, -1, sizeof up);
  dfs(root);
}
