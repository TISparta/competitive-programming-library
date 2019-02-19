/**
 * > Author: TISparta
 * > Date: 25-07-18
 *
 * Z FUNCTION
 *
 * Complexity:
 *
 * > Zfunction: O(|s|)
 *
 * Usage:
 *
 * > Zfunction(s)
 * - Computes z, where
 * - z[0] = 0
 * - z[i] = max{k: s[0..(k-1)] = s[i...(i+k-1)]} 1 <= i < |s|
 *
 */

#include <bits/stdc++.h>

using namespace std;

vector <int> Zfunction (const string s) {
  int n = (int) s.size();
  vector <int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; i++) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n and s[z[i]] == s[i + z[i]]) z[i]++;
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}
