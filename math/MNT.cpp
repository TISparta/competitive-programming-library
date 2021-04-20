// Modular Number Theory
template <class T, T mod>
struct MNT {
  using Mint = Modular <T, mod>;
  vector <Mint> fact;
  vector <Mint> inv_fact;

  void preprocess_factorial (int n) {
    fact.resize(n + 1);
    inv_fact.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
    ll z = 1;
    inv_fact[n] = 1 / fact[n];
    for (int i = n - 1; i >= 0; i--) inv_fact[i] = inv_fact[i + 1] * (i + 1);
  }

  Mint comb (int a, int b) {
    if (a < b) return 0;
    return fact[a] * inv_fact[b] * inv_fact[a - b];
  }
};
