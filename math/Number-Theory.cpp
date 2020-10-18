namespace NT {
  int mod = 1e9 + 7;

  inline int norm (int a) {
    a %= mod;
    if (a < 0) a += mod;
    return a;
  }

  inline int add (int a, int b) {
    int ret = (a + b) % mod;
    if (ret >= mod) ret -= mod;
    return ret;
  }

  inline int sub (int a, int b) {
    int ret = a - b;
    if (ret < 0) ret += mod;
    return ret;
  }

  inline int mul (int a, int b) { 
    return (1LL * a * b) % mod;
  }

  int bin_pow (int a, ll b) {
    int ret = 1;
    while (b) {
      if (b & 1) ret = mul(ret, a);
      a = mul(a, a);
      b >>= 1;
    }
    return ret;
  }

  int inv (int a) {
    return bin_pow(a, mod - 2);
  }
};
