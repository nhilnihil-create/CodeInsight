//
// main.cpp
//

#include <algorithm>
#include <array>
#include <assert.h>
#include <complex>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
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
constexpr ll LL_MAX = numeric_limits<ll>::max();
constexpr ull ULL_MAX = numeric_limits<ull>::max();

template<typename T>
vector<T> make_vec_nd(T init, ll size) {
    return vector<T>(size, init);
}
template<typename T, typename... Args>
auto make_vec_nd(T init, ll size, Args... rest) {
    auto inner = make_vec_nd(init, rest...);
    return vector<decltype(inner)>(size, inner);
}

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrep(i, a, b) for (ll i = (a)-1; i >= (b); i--)

int main() {
    string A;
    cin >> A;
    ll N = A.size();
    vector<ll> can_make_all(N+1);
    unordered_set<char> chars;
    ll len = 0;
    rrep(i,N,0) {
        chars.insert(A[i]);
        if (chars.size() == 26) {
            len++;
            chars.clear();
        }
        can_make_all[i] = len;
    }
    ll ans_len = len + 1;
    unordered_map<char, vector<ll>> first_appear_after;
    rep(ci,0,26) {
        char c = 'a' + ci;
        vector<ll> faa(N+1, N);
        ll fa = N;
        rrep(i,N,0) {
            if (A[i] == c) {
                fa = i;
            }
            faa[i] = fa;
        }
        first_appear_after[c] = move(faa);
    }
    string ans;
    ll see_after = 0;
    while (ans.size() < ans_len){
        char c = 'a';
        rep(ci,0,26) {
            c = 'a' + ci;
            ll faa = first_appear_after[c][see_after];
            if (faa == N) {
                break;
            }
            if (can_make_all[faa+1] < ans_len - ans.size() - 1) {
                break;
            }
        }
        ans.push_back(c);
        see_after = min(N, first_appear_after[c][see_after] + 1);
    }
    cout << ans << endl;
}


