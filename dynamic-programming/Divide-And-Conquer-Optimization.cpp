/**
 * > Author: TISparta
 * > Date: 30-03-19
 *
 * DIVIDE AND CONQUER OPTIMIZATION
 *
 * Complexity:
 *
 * > compute: O(n log n)
 *
 * Usage:
 *
 * > compute(i, 1, n, 0, n - 1)
 * - computes dp[i]
 * - You should've compute dp[i'] [i' < i]
 *
 * Requisites:
 *
 * > dp[i][j] = min(dp[i - 1][k] + cost(k + 1, j)) [1 <= k < j]
 * > best[i][j] <= best[i][j + 1]
 * > cost should be O(1)
 *
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000, MAX_K = 100;

typedef long long ll;

int dp[MAX_K][MAX_N];

inline ll cost (int l, int r) {}

void compute (const int i, int l, int r, int L, int R) {
  if (l > r) return;
  int m = (l + r) >> 1;
  ll bestV = LLONG_MAX, bestK = -1;
  for (int k = L; k <= min(m - 1, R); k++) {
    ll curCost = dp[i - 1][k] + cost(k + 1, m);
    if (curCost < bestV) {
      bestV = curCost;
      bestK = k;
    }
  }
  dp[i][m] = bestV;
  compute(i, l, m - 1, L, bestK);
  compute(i, m + 1, r, bestK, R);
}
