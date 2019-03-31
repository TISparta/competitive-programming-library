/**
 * > Author: TISparta
 * > Date: 25-07-18
 * 
 * PREFIX FUNCTION
 *
 * Complexity:
 *
 * > prefixFunction: O(|s|)
 *
 * Usage:
 *
 * > prefixFunction(s)
 * - Computes pi, where
 * - pi[0] = 0
 * - pi[i] = max{k: s[0...(k-1)] = s[(i-k+1)...i]} 1 <= i < |s|
 *
 */

#include <bits/stdc++.h>

using namespace std;

vector <int> prefixFunction (const string s) {
  int n = s.size();
  vector <int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 and s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}
