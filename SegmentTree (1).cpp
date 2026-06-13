#include <bits/stdc++.h>
using namespace std;

struct Node {
    int sum = 0;
    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    int gcd = 0;
    int count = 0;
    int bit_and = ~0;
    int bit_or = 0;
    int bit_xor = 0;

    Node() = default;

    Node(int value) {
        sum = value;
        minVal = value;
        maxVal = value;
        gcd = value;
        count = 1;
        bit_and = value;
        bit_or = value;
        bit_xor = value;
    }

    static Node merge(const Node &a, const Node &b) {
        Node res(0);
        res.sum = a.sum + b.sum;
        res.minVal = min(a.minVal, b.minVal);
        res.maxVal = max(a.maxVal, b.maxVal);
        res.gcd = __gcd(a.gcd, b.gcd);
        res.count = a.count + b.count;
        res.bit_and = a.bit_and & b.bit_and;
        res.bit_or = a.bit_or | b.bit_or;
        res.bit_xor = a.bit_xor ^ b.bit_xor;
        return res;
    }
};

class SegmentTree {
private:
    int n;
    vector<Node> tree;

    void build(const vector<int> &arr, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = Node(arr[tl]);
        } else {
            int tm = (tl + tr) / 2;
            build(arr, 2*v, tl, tm);
            build(arr, 2*v+1, tm+1, tr);
            tree[v] = Node::merge(tree[2*v], tree[2*v+1]);
        }
    }

    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            tree[v] = Node(new_val);
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(2*v, tl, tm, pos, new_val);
            else
                update(2*v+1, tm+1, tr, pos, new_val);
            tree[v] = Node::merge(tree[2*v], tree[2*v+1]);
        }
    }

    Node query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return Node();
        if (l == tl && r == tr)
            return tree[v];
        int tm = (tl + tr) / 2;
        Node left = query(2*v, tl, tm, l, min(r, tm));
        Node right = query(2*v+1, tm+1, tr, max(l, tm+1), r);
        return Node::merge(left, right);
    }

public:
    SegmentTree(const vector<int> &arr) {
        n = arr.size() - 1;
        tree.resize(4 * (n + 1));
        build(arr, 1, 1, n);
    }

    void update(int pos, int new_val) {
        update(1, 1, n, pos, new_val);
    }

    Node query(int l, int r) {
        return query(1, 1, n, l, r);
    }
};
