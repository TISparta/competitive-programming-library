// Usage example: https://codeforces.com/contest/1202/submission/58471125
const int SIGMA = 26;
  
struct AhoCorasick {

  struct Node {
    vi next;
    vi go;
    int p = -1;
    int ch = -1;
    int link = -1;
    int cnt = 0;
    Node (): next(vi (SIGMA, -1)), go(vi (SIGMA, -1)) {}
    Node (int p, int ch): next(vi(SIGMA, -1)), go(vi(SIGMA, -1)), p(p), ch(ch) {}
    ~Node() {
      next.clear();
      go.clear();
    }
  };

  vector <Node> trie;
  vector <bool> vis;
  void add (const string& s) {
    int u = 0;
    for (char ch: s) {
      int v = ch - 'a';
      if (trie[u].next[v] == -1) {
        trie[u].next[v] = sz(trie);
        trie.push_back(Node(u, ch));
        vis.push_back(false);
      }
      u = trie[u].next[v];
    }
    trie[u].cnt++;
  }
  int getLink (int u) {
    if (trie[u].link == -1) return trie[u].link = (u == 0 or trie[u].p == 0) ? 0 : go(getLink(trie[u].p), trie[u].ch);
    return trie[u].link;
  }
  int go (int u, char ch) {
    int v = ch - 'a';
    if (trie[u].go[v] == -1) {
      if (trie[u].next[v] != -1) return trie[u].go[v] = trie[u].next[v];
      return trie[u].go[v] = (u == 0) ? 0 : go(getLink(u), ch);
    }
    return trie[u].go[v];
  }
  int get (int u) {
    if (u == 0) return 0;
    if (vis[u]) return trie[u].cnt;
    vis[u] = true;
    trie[u].cnt += get(getLink(u));
    return trie[u].cnt;
  }
  AhoCorasick (const vector <string>& arr): trie(vector <Node> (1)), vis(vector <bool> (1, false)) {
    for (const string& s: arr) add(s);
  }
  ~AhoCorasick () {
    trie.clear();
    vis.clear();
  }
  AhoCorasick (): trie(vector <Node> (1)), vis(vector <bool> (1, false)) {}
};
