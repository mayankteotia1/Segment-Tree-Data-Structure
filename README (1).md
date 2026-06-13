# Segment Tree in C++

An efficient and reusable **Segment Tree** implementation in C++ that supports multiple range queries:

- Sum
- Minimum
- Maximum
- GCD
- Bitwise AND
- Bitwise OR
- Bitwise XOR

This implementation is 1-based indexed and built using a clean, modular class-based design.

## 📂 Files

- `SegmentTree.cpp` – Core Segment Tree class with all supported operations.
- `main.cpp` – Sample usage / test driver.
- `README.md` – Project overview.

## 🛠 Features

- No lazy propagation (non-lazy segment tree).
- Modular `Node` struct for storing multiple properties.
- Handles queries in `O(log N)` and updates in `O(log N)`.
- Supports combining multiple queries in a single pass.

## 🚀 Supported Operations

| Operation | Function       |
|----------:|----------------|
| Sum       | `querySum(l, r)` |
| Min       | `queryMin(l, r)` |
| Max       | `queryMax(l, r)` |
| GCD       | `queryGCD(l, r)` |
| AND       | `queryAND(l, r)` |
| OR        | `queryOR(l, r)` |
| XOR       | `queryXOR(l, r)` |

## 🔧 How to Compile

Using `g++`:

```bash
g++ -std=c++17 main.cpp -o segment_tree
./segment_tree
