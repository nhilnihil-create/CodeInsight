//
//  main.cpp
//

#include <algorithm>
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <math.h>
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

using ll = long long;
using ull = unsigned long long;

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
    ll N, M;
    cin >> N >> M;
    vector<unordered_map<ll, ll>> cards(M);
    for (ll i = 0; i < N; i++) {
        ll X;
        cin >> X;
        cards[X % M][X]++;
    }
    ll ans = 0;
    for (ll m = 1; 2 * m < M; m++) {
        ll total[2] = {};
        ll odd_cnt[2] = {};
        for (const auto& kv : cards[m]) {
            total[0] += kv.second;
            odd_cnt[0] += kv.second % 2;
        }
        for (const auto& kv : cards[M-m]) {
            total[1] += kv.second;
            odd_cnt[1] += kv.second % 2;
        }
        if (total[0] < total[1]) {
            swap(total[0], total[1]);
            swap(odd_cnt[0], odd_cnt[1]);
        }
        ans += total[1];
        total[0] -= total[1];
        if (odd_cnt[0] >= total[1]) {
            odd_cnt[0] -= total[1];
        } else {
            odd_cnt[0] = (total[1] - odd_cnt[0]) % 2;
        }
        ans += (total[0] - odd_cnt[0]) / 2;
    }
    // zero case
    {
        ll total = 0;
        for (const auto& kv : cards[0]) {
            total += kv.second;
        }
        ans += total / 2;
    }
    // M/2 case
    if (M % 2 == 0) {
        ll total = 0;
        for (const auto& kv : cards[M / 2]) {
            total += kv.second;
        }
        ans += total / 2;
    }
    cout << ans << endl;
}
