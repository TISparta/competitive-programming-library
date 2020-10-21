struct Dyamic_STree {
  struct State {
    // TODO
  };
  struct NodeParam {
    int l, r;
    int lu, ru;
    NodeParam (int l, int r, int lu, int ru): l(l), r(r), lu(lu), ru(ru) {}
  };
  vector <State> st;
  vector <NodeParam> st_param;
  State NIL; // TODO

  Dyamic_STree (int l, int r) {
    // TODO
    st_param.emplace_back(l, r, -1, -1);
  }

  State merge (State lu, State ru) {
    // TODO
  }

  void push (int u, int l, int r) {
    // TODO
  }

  void update (int L, int R, int val, int u) {
    if (u == -1) return;
    int l = st_param[u].l;
    int r = st_param[u].r;
    push(u, l, r);
    if (r < L or R < l) return;
    if (L <= l and r <= R) {
      // TODO
      push(u, l, r);
      return;
    }
    int m = (l + r) >> 1;
    if (st_param[u].lu == -1) {
      // TODO
      NodeParam lu{l, m, -1, -1};
      st_param[u].lu = sz(st);
      st_param.pb(lu);
    }
    if (st_param[u].ru == -1) {
      // TODO
      NodeParam ru{m + 1, r, -1, -1};
      st_param[u].ru = sz(st);
      st_param.pb(ru);
    }
    int lu = st_param[u].lu;
    int ru = st_param[u].ru;
    update(L, R, val, lu);
    update(L, R, val, ru);
    st[u] = merge(st[lu], st[ru]);
  }

  void update (int L, int R, int val) { update(L, R, val, 0); }

  State query (int L, int R, int u) {
    if (u == -1) return NIL;
    int l = st_param[u].l;
    int r = st_param[u].r;
    push(u, l, r);
    if (r < L or R < l) return NIL;
    if (L <= l and r <= R) return st[u];
    return merge(query(L, R, st_param[u].lu), query(L, R, st_param[u].ru));
  }

  State query (int L, int R) { return query(L, R, 0); }

};
