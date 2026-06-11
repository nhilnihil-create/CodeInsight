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

int main() {
    ll N, M;
    cin >> N >> M;
    struct Edge {
        ll from;
        ll to;
    };
    vector<Edge> edges;
    rep(i,0,M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        edges.push_back(Edge{a, b});
        edges.push_back(Edge{b, a});
    }
    ll Q;
    cin >> Q;
    struct Query {
        ll v;
        ll d;
        ll c;
    };
    vector<Query> queries(Q);
    rep(q,0,Q) {
        ll v, d, c;
        cin >> v >> d >> c;
        v--;
        queries[q] = {v, d, c};
    }
    struct Data {
        ll p; // priority
        ll c; // color
        void add(const Data& rhs) {
            if (rhs.p > p) {
                *this = rhs;
            }
        }
    };
    vector<vector<Data>> data(N);
    rep(i,0,N) {
        data[i] = vector<Data>(11, Data{-1, 0});
    }
    rep(i,0,Q) {
        Query q = queries[i];
        data[q.v][q.d].add(Data{i, q.c});
    }
    rep(loop,0,11) {
        for (Edge& e : edges) {
            rep(d,1,11) {
                data[e.to][d-1].add(data[e.from][d]);
            }
        }
    }
    rep(i,0,N) {
        Data ans{-1, 0};
        rep(d,0,11) {
            ans.add(data[i][d]);
        }
        cout << ans.c << endl;
    }
}

