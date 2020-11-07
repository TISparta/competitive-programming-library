ll cost (int l, int r) {}

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
