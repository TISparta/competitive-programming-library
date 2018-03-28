/**
 * > Author : TISparta
 * > Date : 27-03-18
 *
 * Fenwick Tree (a.k.a Binary Indexed Tree (BIT))
 * Complexity
 * > update : O(log n)
 * > getLeftSum : O(log n)
 * > getRightSum : O(log n)
 */

#include <bits/stdc++.h>
 
using namespace std;

template <typename T>
struct BIT {
    int sz;
    vector <T> ft;
    BIT() {}

    void init(const int sz_) {
        sz = sz_;
        ft.resize(sz, 0);
    }

    void update(int pos, const T& val) {
        while (pos < sz) {
            ft[pos] += val;
            pos += pos bitand -pos;
        }
    }

    T getLeftSum(int pos) {
        T sum = 0;
        while (pos) {
            sum += ft[pos];
            pos = pos bitand (pos - 1);
        }
        return sum;
    }

    T getRightSum(int pos) {
        return getLeftSum(sz - 1) - getLeftSum(pos - 1);
    }
 
};
