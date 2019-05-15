/**
 * > Author: TISparta
 * > Date: 15-05-19
 *
 * SEGMENT TREE
 *
 * Legend:
 * 
 * > arr : array with numbers
 * > n : max element of `arr`
 *
 * Complexity:
 *
 * > STree: O(n)
 * > update : O(log n)
 * > query : O(log n)
 *
 * Usage:
 *
 * > STree(arr, l, r)
 * - Create a segment tree from the elements between `l` and `r` of `arr`
 *
 * > update(L, R, val)
 * - Updates range [L, R]. `val` may change according to the problem
 *
 * > get(L, R)
 * - Get the state from [L, R]
 *
 * Remarks:
 *
 * - Be carefully with initializations
 * - If time limit is too strict dont use this version (you should save your
 *   segment tree in array fixed size)
 * - It you dont need lazy propagation, just dont define the `push` function
 *
 */

#include <bits/stdc++.h>

using namespace std;

struct State {
  // DEFINE THE STATE
  State() {}
} NIL;

State merge (const State& x, const State& y) {
  State ret;
  // TO DO
  return move(ret);
}

struct Lazy {
  // DEFINE THE LAZY
  Lazy () {}
};

struct STree {
  int l, r;
  State state;
  Lazy lazy;
  STree* left = 0;
  STree* right = 0;
  STree (const vector <int>& arr, int l, int r): l(l), r(r) {
    if (l == r) {
      // state = SOMETHING
      return;
    }
    int m = (l + r) >> 1;
    left = new STree(arr, l, m);
    right = new STree(arr, m + 1, r);
    state = merge(left -> state, right -> state);
  }
  void push () {
    // if (lazy == SOMETHING) return;
    if (l != r) {
      // left -> lazy = SOMETHING
      // right -> lazy = SOMETHING
    }
    // lazy = SOMETHING
  }
  void update (const int L, const int R, const int val) {
    push();
    if (r < L or R < l) return;
    if (L <= l and r <= R) {
      // Lazy = SOMETHING
      push();
      return;
    }
    left -> update(L, R, val);
    right -> update(L, R, val);
    state = merge(left -> state, right -> state);
  }
  State get (const int L, const int R) {
    push();
    if (r < L or R < l) return NIL;
    if (L <= l and r <= R) return state;
    return merge(left -> get(L, R), right -> get(L, R));
  }
};
