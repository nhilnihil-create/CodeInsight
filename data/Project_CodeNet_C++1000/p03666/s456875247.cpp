//
//  main.cpp
//

#include <algorithm>
#include <array>
#include <assert.h>
#include <iomanip>
#include <iostream>
#include <limits>
#include <math.h>
#include <memory>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = int64_t;
using ull = uint64_t;

template<typename T>
vector<T> make_vec_nd(T init, size_t size) {
    return vector<T>(size, init);
}
template<typename T, typename... Args>
auto make_vec_nd(T init, size_t size, Args... rest) {
    auto inner = make_vec_nd(init, rest...);
    return vector<decltype(inner)>(size, inner);
}

int main() {
    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    ll X = abs(A - B);
    ll E = D - C;
    ll right = N / 2;
    while (true) {
        ll left = (N - 1) - right;
        if (left < 0) {
            cout << "NO" << endl;
            return 0;
        }
        if ((right - left) * C - left * E <= X && X <= (right - left) * C + right * E) {
            cout << "YES" << endl;
            return 0;
        }
        if (X < (right - left) * C - left * E) {
            cout << "NO" << endl;
            return 0;
        }
        right++;
    }
}

