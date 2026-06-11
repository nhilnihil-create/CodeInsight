#include <stdio.h>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <iomanip>
//#include <unordered_map>
//#include <unordered_set>
//#include <boost/container/static_vector.hpp>
//#include <boost/unordered_set.hpp>
//#include <boost/unordered_map.hpp>
//#include <unistd.h>

class BIT {
    // Binary Indexed Tree : 数列要素1つへの加算、数列のある地点までの累積和を高速に計算
    public:
    std::vector<int> data;
    BIT() {}
    BIT(const int size) {
        // 想定されるサイズの2倍の値を入れた方がいいかもしれない。
        data.resize(size, 0);
    }
    int sum(int i) const {
        int s = 0;
        while (i > 0) {
            s += data[i];
            i = i & (i-1); // iの最後のビットを引く。
        }
        return s;
    }

    void add(int i, int x) {
        while (i < data.size()) {
            data[i] += x;
            i += i - (i & (i-1)); // iの最後のビットを加算する。
        }
    }
};

class BIT2 {
    // Binary Indexed Tree 2つ : 数列区間への加算、数列のある地点までの累積和を高速に計算。
    public:
    BIT bit[2];
    BIT2() {}
    BIT2(const int size) {
        bit[0] = BIT(size);
        bit[1] = BIT(size);
    }
    int sum(int i) const {
        return bit[1].sum(i) * i + bit[0].sum(i);
    }
    void add(int l, int r, int x) {
        // [l,r]にxを加算。閉区間であり、rを含む点に注意。l=rの時、一つの値のみを操作できることになる。
        bit[0].add(l, -x * (l - 1));
        bit[1].add(l, x);
        bit[0].add(r + 1, x * r);
        bit[1].add(r + 1, -x);
    }
};

const int MAX_N = 300050;
const int MAX_M = 100050;

int N, M;

int L[MAX_N], R[MAX_N];

std::vector<int> seg[MAX_M];
int seg_ac[MAX_M] = {};
BIT2 bit = BIT2(MAX_M * 2);

int ret[MAX_M] = {};

int main(int argc, char **argv) {
    std::cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        std::cin >> L[i] >> R[i];
    }

    for (int i = 1; i <= N; i++) {
        seg[R[i] - L[i]].push_back(L[i]);
    }

    seg_ac[M + 1] = 0;
    for (int m = M; 0 <= m; m--) {
        seg_ac[m] = seg_ac[m+1] + seg[m].size();
    }

    for (int d = 1; d <= M; d++) {
        ret[d] = seg_ac[d-1];
        for (int i = d; i <= M; i += d) {
            ret[d] += bit.sum(i) - bit.sum(i-1);
        }

        for (int s : seg[d - 1]) {
            bit.add(s, s + d - 1, 1);
        }
    }

    for (int d = 1; d <= M; d++) {
        std::cout << ret[d] << std::endl;
    }
    
    return 0;
}