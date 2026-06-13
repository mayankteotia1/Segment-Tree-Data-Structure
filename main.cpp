#include <bits/stdc++.h>
#include "SegmentTree.cpp"
using namespace std;

int main() {
    vector<int> arr = {0, 5, 1, 3, 7, 9}; 
    SegmentTree st(arr);

    Node res1 = st.query(2, 4);
    cout << "Sum (2-4): " << res1.sum << "\n";
    cout << "Min (2-4): " << res1.minVal << "\n";
    cout << "Max (2-4): " << res1.maxVal << "\n";
    cout << "GCD (2-4): " << res1.gcd << "\n";
    cout << "XOR (2-4): " << res1.bit_xor << "\n";

    st.update(3, 10);
    Node res2 = st.query(2, 4);
    cout << "After update: Sum (2-4): " << res2.sum << "\n";

    return 0;
}
