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
    ll N;
    cin >> N;
    vector<ll> Pis;
    for (ll i = 0; i < N; i++) {
        ll Pi;
        cin >> Pi;
        Pis.push_back(Pi);
    }
    struct ValInfo {
        ll idx;
        ll value;
    };
    auto comp_val_info_0 = [](ValInfo lhs, ValInfo rhs){ return lhs.value < rhs.value; };
    priority_queue<ValInfo, vector<ValInfo>, decltype(comp_val_info_0)> queue0(comp_val_info_0);
    vector<ll> right_map0(N, N);
    for (ll i = 0; i < N; i++) {
        ll Pi = Pis[i];
        while (!queue0.empty() && queue0.top().value > Pi) {
            ValInfo info = queue0.top();
            queue0.pop();
            right_map0[info.idx] = i;
        }
        queue0.push(ValInfo{i, Pis[i]});
    }
    while (!queue0.empty()) {
        queue0.pop();
    }
    vector<ll> left_map0(N, -1);
    for (ll i = N-1; i >= 0; i--) {
        ll Pi = Pis[i];
        while (!queue0.empty() && queue0.top().value > Pi) {
            ValInfo info = queue0.top();
            queue0.pop();
            left_map0[info.idx] = i;
        }
        queue0.push(ValInfo{i, Pis[i]});
    }
    ll ans = 0;
    for (ll i = 0; i < N; i++) {
        ll cnt = 0;
        cnt += (i - left_map0[i]) * (right_map0[i] - i);
        ans += cnt * Pis[i];
    }
    cout << ans << endl;
}

