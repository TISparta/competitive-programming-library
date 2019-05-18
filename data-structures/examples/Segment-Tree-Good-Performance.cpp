// > Problem: https://www.spoj.com/problems/HORRIBLE/
// > Author: TISparta
// > Time: 0.14 seconds
// > Date: 18-05-19

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

class STree {
private:
  int l, r;
  vector <State> st;
  vector <Lazy> lazy;

  void build (const vector <int>& arr, int node, int l, int r) {
    if (l == r) {
      st[node].sum = arr[l];
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
    if (lazy[node].add == 0) return;
    st[node].sum += 1LL * (r - l + 1) * lazy[node].add;
    if (l != r) {
      lazy[node * 2].add += lazy[node].add;
      lazy[node * 2 + 1].add += lazy[node].add;
    }
    lazy[node].add = 0;
  }

  void update (int node, int l, int r, int L, int R, int val) {
    push(node, l, r);
    if (r < L or R < l) return;
    if (L <= l and r <= R) {
      lazy[node].add = val;
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
