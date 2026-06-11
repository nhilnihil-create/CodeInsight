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
    ll N, X;
    cin >> N >> X;
    vector<ll> Ais;
    for (ll i = 0; i < N; i++) {
        ll Ai;
        cin >> Ai;
        Ais.push_back(Ai);
    }
    struct Info {
        ll idx;
        ll value;
    };
    auto mod = [N](ll x) -> ll {
        return ((x % N) + N) % N;
    };
    ll ans = numeric_limits<ll>::max();
    for (ll magic = 0; magic <= N-1; magic++) {
        deque<Info> deq;
        vector<ll> count(N);
        ll end = N-1;
        for (ll start = N-1; start >= 0; start--) {
            do {
                while (!deq.empty() && deq.back().value >= Ais[end]) {
                    deq.pop_back();
                }
                deq.push_back(Info{end, Ais[end]});
                end = mod(end - 1);
            } while (end != mod(start - magic - 1));
            count[deq.front().idx]++;
            if (deq.front().idx == start) {
                deq.pop_front();
            }
        }
        ll cost = 0;
        for (ll i = 0; i < N; i++) {
            cost += Ais[i] * count[i];
        }
        cost += magic * X;
        ans = min(ans, cost);
    }
    cout << ans << endl;
}