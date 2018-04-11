#include <bits/stdc++.h>

using namespace std;

const int NOT_FOUND = INT_MAX;

typedef int ktype;
typedef long long ptype;

struct Tnode {

    ktype key;
    ptype priority;
    Tnode* left = 0;
    Tnode* right = 0;
    size_t sz;

    Tnode(ktype key_):
        key(key_),
        priority(rand()),
        sz(1) {}
    ~Tnode() {
        delete left;
        delete right;
    }

};

typedef Tnode* pnode;

namespace Treap {

    void setSeed() {
        srand(time(0));
    }

    inline size_t len(pnode& root) {
        return root ? root -> sz : 0;
    }

    inline void updateLen(pnode& root) {
        if (root) root -> sz = len(root -> left) + len(root -> right) + 1;
    }

    bool find(pnode& root, ktype key) {
        if (not root or root -> key == key) return root;
        return find(key < root -> key ? root -> left : root -> right, key);
    }

    void split(pnode root, pnode& left, pnode& right, ktype key) {
        if (not root) {
            left = right = 0;
            return;
        }
        if (key < root -> key) split(root -> left, left, root -> left, key), right = root;
        else split(root -> right, root -> right, right, key), left = root;
        updateLen(root);
    }

    void insert(pnode& root, pnode new_node) {
        if (!root) root = new_node;
        else if (root -> priority > new_node -> priority)
            split(root, new_node -> left, new_node -> right, new_node -> key), root = new_node;
        else insert(new_node -> key < root -> key ? root -> left : root -> right, new_node);
        updateLen(root);
    }

    void merge(pnode& root, pnode left, pnode right) {
        if (not left) root = right;
        else if (not right) root = left;
        else if (left -> priority > right -> priority)
            merge(left -> right, left -> right, right), root = left;
        else
            merge(right -> left, left, right -> left), root = right;
        updateLen(root);
    }

    void erase(pnode& root, ktype key) {
        if (root -> key == key) merge(root, root -> left, root -> right);
        else erase(key < root -> key ? root -> left : root -> right, key);
        updateLen(root);
    }

    ktype kth(pnode root, int k) {
        if (not root) return NOT_FOUND;
        if (1 + len(root -> left) == k) return root -> key;
        if (len(root -> left) < k) return kth(root -> right, k - 1 - len(root -> left));
        return kth(root -> left, k);
    }

    int lt(pnode root, int key) {
        if (not root) return 0;
        if (root -> key == key) return len(root -> left);
        if (root -> key < key) return len(root -> left) + 1 + lt(root -> right, key);
        if (root -> key > key) return lt(root -> left, key);
    }

}
