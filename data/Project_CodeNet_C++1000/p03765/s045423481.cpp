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

ll good_mod(ll val, ll base) {
    return (val % base + base) % base;
};

ll inv0(const vector<ll>& cnt, ll end) {
    return good_mod(cnt[end] + 2 * (end - cnt[end]), 3);
};

ll inv1(const vector<ll>& cnt, ll start, ll end) {
    return good_mod(inv0(cnt, end) - inv0(cnt, start), 3);
};

int main() {
    string S;
    string T;
    cin >> S;
    cin >> T;
    vector<ll> cnt_s(S.size() + 1);
    for (ll n = 1; n <= S.size(); n++) {
        cnt_s[n] = cnt_s[n-1] + (S[n-1] == 'A');
    }
    vector<ll> cnt_t(T.size() + 1);
    for (ll n = 1; n <= T.size(); n++) {
        cnt_t[n] = cnt_t[n-1] + (T[n-1] == 'A');
    }
    ll q;
    cin >> q;
    for (ll i = 0; i < q; i++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        c--;
        if (inv1(cnt_s, a, b) == inv1(cnt_t, c, d)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

