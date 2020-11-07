struct Line {
  ll m, c;
  ll eval (ll x) {
    return m * x + c;
  }
};

bool ccw (Line o, Line a, Line b) {
  pll v1(a.m - o.m, a.c - o.c);
  pll v2(b.m - o.m, b.c - o.c);
  return (v1.first * v2.second - v1.second * v2.first) >= 0;
}

struct CHT {
  vector <Line> line;

  void add (const Line l) {
    while (sz(line) >= 2 and ccw(end(line)[-2], end(line)[-1], l)) {
      line.pop_back();
    }
    line.pb(l);
  }
  
  ll get_min (ll x) {
    ll l = 0;
    ll r = sz(line) - 1;
    while (l != r) {
      ll m = (l + r) >> 1;
      if (line[m].eval(x) < line[m + 1].eval(x)) r = m;
      else l = m + 1;
    }
    return line[l].eval(x);
  }
};
