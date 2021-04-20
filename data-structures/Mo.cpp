// 0-indexing
int B;
struct Mo {
  struct Query {
    int l, r, id;
    Query () {}
    Query (int l, int r, int id): l(l), r(r), id(id) {}
    bool operator < (const Query& other) const {
      int x = l / B;
      int y = other.l / B;
      if (x != y) return x < y;
      return r < other.r;
    };
  };
  
  int n;
  int q;
  vector <Query> query;
  // TODO: SET MORE VARIABLES

  vector <Query> query;
  Mo (int n, int q): n(n), q(q) {
    B = 1 + sqrt(n);
    query.reserve(q);
  };

  void add_query (int l, int r) {
    query.emplace_back(l, r, sz(query));
  };

  void add (int pos) {
    // TODO
  }

  void remove (int pos) {
    // TODO
  };

  void solve (vi& ans) {
    // TODO: Init variables
    sort(all(query));
    int L = 0, R = -1;
    for (auto [l, r, i]: query) {
      while (L > l) add(--L);
      while (R < r) add(++R);
      while (L < l) remove(L++);
      while (R > r) remove(R--);
      ans[i] = // TODO
    }
  };

};
