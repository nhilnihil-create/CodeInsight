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
    vector<ll> Ais;
    for (ll i = 0; i < N; i++) {
        ll Ai;
        cin >> Ai;
        Ais.push_back(Ai);
    }
    ll mx = 0;
    ll ans = 0;
    for (ll i = 0; i < N; i++) {
        ll buy = (Ais[i] % (mx + 1) != 0) ? Ais[i] / (mx + 1) : Ais[i] / (mx + 1) - 1;
        ans += buy;
        Ais[i] -= buy * (mx + 1);
        if (Ais[i] >= 2 && buy >= 1) {
            Ais[i]--;
        }
        mx = max(mx, Ais[i]);
    }
    cout << ans << endl;
}

