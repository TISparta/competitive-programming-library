namespace NT {
  int mod = 998244353;
  vi fact;
  vi inv_fact;

  inline int norm (ll a) {
    a %= mod;
    if (a < 0) a += mod;
    return a;
  }

  inline int add (ll a, ll b) {
    ll ret = a + b;
    if (ret >= mod) ret -= mod;
    return ret;
  }

  inline int sub (ll a, ll b) {
    ll ret = a - b;
    if (ret < 0) ret += mod;
    return ret;
  }

  inline int mul (ll a, ll b) {
    return (a * b) % mod;
  }

  int bin_pow (ll a, ll b) {
    int ret = 1;
    while (b) {
      if (b & 1) ret = mul(ret, a);
      a = mul(a, a);
      b >>= 1;
    }
    return ret;
  }

  int inv (ll a) {
    return bin_pow(a, mod - 2);
  }

  void preprocess_factorial (int n) {
    fact.resize(n + 1);
    inv_fact.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = mul(fact[i - 1], i);
    inv_fact[n] = inv(fact[n]);
    for (int i = n - 1; i >= 0; i--) inv_fact[i] = mul(inv_fact[i + 1], i + 1);
  }

  int comb (int a, int b) {
    if (a < b) return 0;
    return mul(mul(fact[a], inv_fact[b]), inv_fact[a - b]);
  }
};
