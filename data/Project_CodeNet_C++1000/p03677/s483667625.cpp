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
#include <unordered_map>
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
        // 想定されるサイズの2倍の値を入れた方がいいかもしれない。数列は1から数えることを想定している。
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

const int MAX_N = 100050;
int N, M;
int a[MAX_N];

BIT2 bit = BIT2(MAX_N * 2);

int to_next_simple(const int k1, const int k2) {
    if (k1 <= k2) {
        return k2 - k1;
    } else {
        return M + k2 - k1;
    }
}

int to_next(const int k1, const int k2, const int x) {
    return std::min(to_next_simple(k1, k2), 1 + to_next_simple(x, k2));
}

int step_add(const int k, const int add) {
    if (k + add <= M) {
        return k + add;
    } else {
        k + add - M;
    }
}

long long ret[MAX_N] = {};

int main(int argc, char **argv) {
    std::cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        std::cin >> a[i];
    }

    for (int i = 2; i <= N; i++) {
        if (a[i-1] < a[i] && 2 <= a[i] - a[i-1]) {
            bit.add(a[i-1] + 2, a[i], -1);
            int next = (a[i] == M) ? 1 : a[i] + 1;
            bit.add(next, next, a[i] - a[i-1] - 1);
        } else if (a[i] < a[i-1] && 2 <= a[i] + M - a[i-1]) {
            if (a[i-1] + 2 <= M) {
                bit.add(a[i-1] + 2, M, -1);
                bit.add(1, a[i], -1);
            } else {
                bit.add(a[i-1] + 2 - M, a[i], -1);
            }
            bit.add(a[i] + 1, a[i] + 1, a[i] + M - a[i-1] - 1);
        }
        //std::cout << "check:" << i << " " << bit.sum(M) - bit.sum(M-1) << std::endl;
    }

    for (int i = 2; i <= N; i++) {
        //std::cout << "to_next:" << i << " " << to_next(a[i-1], a[i], 1) << std::endl;
        ret[1] += to_next(a[i-1], a[i], 1);
    }

    long long ret_min = ret[1];
    //std::cout << 1 << " " << ret[1] << std::endl;
    for (int i = 2; i <= M; i++) {
        ret[i] = ret[i-1] + bit.sum(i) - bit.sum(i-1);
        //std::cout << i << " " << ret[i] << std::endl;
        ret_min = std::min(ret_min, ret[i]);
    }

    std::cout << ret_min << std::endl;
    
    return 0;
}
