#include <bits/stdc++.h>
using namespace std;

int __gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return __gcd(b, a % b);
}

struct Node
{
    // Aggregate values stored for a segment
    int sum = 0;

    int minVal = INT_MAX;
    int maxVal = INT_MIN;

    int gcd = 0;
    int count = 0;

    int bit_and = ~0;
    int bit_or = 0;
    int bit_xor = 0;

    Node() = default;

    // Leaf node constructor
    Node(int value)
    {
        sum = value;

        minVal = value;
        maxVal = value;

        gcd = value;
        count = 1;

        bit_and = value;
        bit_or = value;
        bit_xor = value;
    }

    // Merge two child nodes
    static Node merge(const Node &leftNode, const Node &rightNode)
    {
        Node result;

        result.sum = leftNode.sum + rightNode.sum;

        result.minVal = min(leftNode.minVal, rightNode.minVal);
        result.maxVal = max(leftNode.maxVal, rightNode.maxVal);

        result.gcd = __gcd(leftNode.gcd, rightNode.gcd);
        result.count = leftNode.count + rightNode.count;

        result.bit_and = leftNode.bit_and & rightNode.bit_and;
        result.bit_or = leftNode.bit_or | rightNode.bit_or;
        result.bit_xor = leftNode.bit_xor ^ rightNode.bit_xor;

        return result;
    }
};

class SegmentTree
{
private:
    int n;
    vector<Node> tree;

    // Build the segment tree
    void build(const vector<int> &arr, int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = Node(arr[start]);
            return;
        }

        int mid = (start + end) / 2;

        build(arr, 2 * node, start, mid);
        build(arr, 2 * node + 1, mid + 1, end);

        tree[node] = Node::merge(tree[2 * node],
                                 tree[2 * node + 1]);
    }

    // Point update
    void update(int node, int start, int end, int position, int newValue)
    {
        if (start == end)
        {
            tree[node] = Node(newValue);
            return;
        }

        int mid = (start + end) / 2;

        if (position <= mid)
        {
            update(2 * node, start, mid, position, newValue);
        }
        else
        {
            update(2 * node + 1, mid + 1, end, position, newValue);
        }

        tree[node] = Node::merge(tree[2 * node],
                                 tree[2 * node + 1]);
    }

    // Range query
    Node query(int node, int start, int end, int left, int right)
    {
        if (left > right)
        {
            return Node();
        }

        if (start == left && end == right)
        {
            return tree[node];
        }

        int mid = (start + end) / 2;

        Node leftPart =
            query(2 * node,
                  start,
                  mid,
                  left,
                  min(right, mid));

        Node rightPart =
            query(2 * node + 1,
                  mid + 1,
                  end,
                  max(left, mid + 1),
                  right);

        return Node::merge(leftPart, rightPart);
    }

public:
    SegmentTree(const vector<int> &arr)
    {
        // Assumes 1-indexed array
        n = (int)arr.size() - 1;

        tree.resize(4 * (n + 1));

        build(arr, 1, 1, n);
    }

    // Public point update
    void update(int position, int newValue)
    {
        update(1, 1, n, position, newValue);
    }

    // Public range query
    Node query(int left, int right)
    {
        return query(1, 1, n, left, right);
    }
};s
