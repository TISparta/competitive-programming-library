/**
 * > Author: TISparta
 * > Date: 18-05-19
 *
 * SEGMENT TREE
 *
 * Legend:
 * 
 * > arr : array with numbers
 * > n : number of elements of `arr`
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
 * - Create a segment tree from the elements in [l, r] of `arr`
 *
 * > update(L, R, val)
 * - Updates range [L, R]. `val` may change according to the problem
 *
 * > get(L, R)
 * - Get the state from [L, R]
 *
 * Remarks:
 *
 * - NIL must have this property: merge(x, NIL) = x
 * - Be carefully with initializations
 * - It you dont need lazy propagation, just dont define the `push` function
 *
 */

#include <bits/stdc++.h>

using namespace std;

struct State {
  // DEFINE THE STATE
  State () {}
} NIL; // INIT NIL

State merge (const State& x, const State& y) {
  State ret;
  // TO DO
  return move(ret);
}

struct Lazy {
  // DEFINE THE LAZY
  Lazy () {}
};

class STree {
private:
  int l, r;
  vector <State> st;
  vector <Lazy> lazy;

  void build (const vector <int>& arr, int node, int l, int r) {
    if (l == r) {
      // st[node] = SOMETHING
      return;
    }
    int m = (l + r) >> 1;
    int left = node << 1;
    int right = left | 1;
    build(arr, left, l, m);
    build(arr, right, m + 1, r);
    st[node] = merge(st[left], st[right]);
  }

  void push (int node, int l, int r) {
    // if (lazy[node] == SOMETHING) return;
    if (l != r) {
      // lazy[node * 2] = SOMETHING
      // lazy[node * 2 + 1] = SOMETHING
    }
    // lazy[node] = SOMETHING
  }

  void update (int node, int l, int r, int L, int R, int val) {
    push(node, l, r);
    if (r < L or R < l) return;
    if (L <= l and r <= R) {
      // lazy[node] = SOMETHING
      push(node, l, r);
      return;
    }
    int m = (l + r) >> 1;
    int left = node << 1;
    int right = left | 1;
    update(left, l, m, L, R, val);
    update(right, m + 1, r, L, R, val);
    st[node] = merge(st[left], st[right]);
  }

  State get (int node, int l, int r, int L, int R) {
    push(node, l, r);
    if (r < L or R < l) return NIL;
    if (L <= l and r <= R) return st[node];
    int m = (l + r) >> 1;
    return merge(get(2 * node, l, m, L, R), get(2 * node + 1, m + 1, r, L, R));
  }

public:
  STree (vector <int>& arr, int l, int r): l(l), r(r) {
    st.assign(4 * r, State());
    lazy.assign(4 * r, Lazy());
    build(arr, 1, l, r);
  }
  void update (int L, int R, int val) {
    update(1, l, r, L, R, val);
  }
  State get (int L, int R) {
    return get(1, l, r, L, R);
  }
};
