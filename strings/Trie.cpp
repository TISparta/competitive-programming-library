struct Trie {
  const static int SIGMA = 26;

  struct Node {
    vi nxt;
    Node () { 
      nxt = vi(SIGMA, -1);
    }
  };

  vector <Node> trie;

  Trie () {
    trie.pb(Node{});
  }

  void add (const string& s) {
    int cur = 0;
    for (char ch: s) {
      int u = ch - 'a';
      if (trie[cur].nxt[u] == -1) {
        trie[cur].nxt[u] = sz(trie);
        trie.pb(Node{});
      }
      cur = trie[cur].nxt[u];
    }
  }

};
