//
//  main.cpp
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

void calc_grundy(ll now, vector<vector<ll>>& graph, vector<ll>& grundy, vector<bool>& visited) {
    visited[now] = true;
    ll g = 0;
    for (ll to : graph[now]) {
        if (visited[to]) {
            continue;
        }
        calc_grundy(to, graph, grundy, visited);
        g = g ^ (grundy[to] + 1);
    }
    grundy[now] = g;
}

int main() {
    ll N;
    cin >> N;
    vector<vector<ll>> graph(N);
    rep(i,0,N-1) {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<bool> visited(N);
    vector<ll> grundy(N);
    calc_grundy(0, graph, grundy, visited);
    if (grundy[0] == 0) {
        cout << "Bob" << endl;
    } else {
        cout << "Alice" << endl;
    }
}
