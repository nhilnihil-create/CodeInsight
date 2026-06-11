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
    vector<ll> ais(N);
    unordered_map<ll, ll> ais_cnt;
    for (ll i = 0; i < N; i++) {
        cin >> ais[i];
        ais_cnt[ais[i]]++;
    }
    if (ais_cnt.size() >= 3) {
        cout << "No" << endl;
        return 0;
    }
    if (ais_cnt.size() == 1) {
        ll val = ais_cnt.begin()->first;
        if (N == val + 1) {
            cout << "Yes" << endl;
            return 0;
        } else if (N >= val * 2) {
            cout << "Yes" << endl;
            return 0;
        } else {
            cout << "No" << endl;
            return 0;
        }
    } else {
        ll a = ais_cnt.begin()->first;
        ll b = next(ais_cnt.begin())->first;
        ll groups = max(a, b);
        ll singletons = ais_cnt[groups-1];
        ll non_singletons = groups - singletons;
        if (singletons <= 0 || non_singletons <= 0) {
            cout << "No" << endl;
            return 0;
        }
        if (N < singletons + 2 * non_singletons) {
            cout << "No" << endl;
            return 0;
        }
        cout << "Yes" << endl;
        return 0;
    }
}

