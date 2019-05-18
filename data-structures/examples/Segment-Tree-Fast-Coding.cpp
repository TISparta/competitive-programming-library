// > Problem: https://www.spoj.com/problems/HORRIBLE/
// > Author: TISparta
// > Time: 0.18 seconds
// > Date: 15-05-19

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct State {
  ll sum = 0;
  State () {}
  State (ll sum): sum(sum) {}
} NIL(0LL);

State merge (const State& x, const State& y) {
  State ret;
  ret.sum = x.sum + y.sum;
  return move(ret);
}

struct Lazy {
  ll add = 0;
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
      state.sum = arr[l];
      return;
    }
    int m = (l + r) >> 1;
    left = new STree(arr, l, m);
    right = new STree(arr, m + 1, r);
    state = merge(left -> state, right -> state);
  }
  void push () {
    if (lazy.add == 0) return;
    state.sum += 1LL * (r - l + 1) * lazy.add;
    if (l != r) {
      left -> lazy.add += lazy.add;
      right -> lazy.add += lazy.add;
    }
    lazy.add = 0;
  }
  void update (const int L, const int R, const int val) {
    push();
    if (r < L or R < l) return;
    if (L <= l and r <= R) {
      lazy.add = val;
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

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, q;
    cin >> n >> q;
    vector <int> arr(n + 1, 0);
    STree tree(arr, 1, n);
    while (q--) {
      int type;
      cin >> type;
      if (type == 0) {
        int l, r, v;
        cin >> l >> r >> v;
        tree.update(l, r, v);
      } else {
        int l, r;
        cin >> l >> r;
        cout << tree.get(l, r).sum << '\n';
      }
    }
  }
}
