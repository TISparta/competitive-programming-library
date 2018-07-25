/**
 * > Author: TISparta
 * > Date: 27-03-18
 *
 * FENWICK TREE (a.k.a BINARY INDEXED TREE (BIT))
 *
 * Legend:
 * 
 * > arr : array with numbers
 * > n : max element of `arr`
 *
 * Complexity:
 *
 * > init: O(n)
 * > update : O(log n)
 * > getLeftSum : O(log n)
 * > getRightSum : O(log n)
 *
 * Usage:
 *
 * > init(n)
 * - Init the array with `n` zero elements
 *
 * > update(pos, val)
 * - Add `val` to `arr[pos]` and update the cumulate sums
 * - 1 <= pos < n
 *
 * > getLeftSum(pos)
 * - Sum of `arr[i]` with `1 <= i <= pos`
 * - 1 <= pos < n
 *
 * > getRightSum(pos)
 * - Sum of `arr[i]` with `pos <= i < n`
 * - 1 <= pos < n
 *
 * Remarks:
 *
 * - Note that `arr` can be an array of indices or values
 *
 */

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

struct BIT {
  int n;
  vector <ll> ft;
  BIT() {}

  void init(const int n_) {
    n = n_;
    ft.resize(n, 0);
  }

  void update(int pos, const ll val) {
    while (pos < n) {
      ft[pos] += val;
      pos += pos bitand -pos;
    }
  }

  ll getLeftSum(int pos) {
    ll sum = 0;
    while (pos) {
      sum += ft[pos];
      pos = pos bitand (pos - 1);
    }
    return sum;
  }

  ll getRightSum(int pos) {
    return getLeftSum(n - 1) - getLeftSum(pos - 1);
  }
 
};
