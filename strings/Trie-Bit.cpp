struct TrieBit {
  struct Trie {
    int child[2] = {-1, -1};
    int cnt = 0;
  };
  const int LG = 31;
  vector <Trie> trie;

  TrieBit () {
    trie.pb(Trie{});
  }

  void update (int num, int flag) {
    int node = 0;
    for (int bit = LG; bit >= 0; bit--) {
      int b = (num >> bit) & 1;
      if (trie[node].child[b] == -1) {
        trie[node].child[b] = sz(trie);
        trie.pb(Trie{});
      }
      node = trie[node].child[b];
      trie[node].cnt += flag;
    }
  }
};
