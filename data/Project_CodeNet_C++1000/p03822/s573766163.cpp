#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <fstream>
#include <cmath>
#include <random>
#include <complex>
#include <functional>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)
using namespace std;
typedef vector<ll> vec;
typedef vector<vec> mat;

const ll inf = 1LL << 60;

template<class T> inline void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}
template<class T> inline void chmax(T& a, T b) {
    if (a < b) {
        a = b;
    }
}

typedef pair<ll, ll> P;
vec d;
struct edge {
    ll to, cost;
};
vector<vector<edge>> G;

void dijkstra (ll s, ll V) {
    priority_queue<P, vector<P>, greater<P>> que;
    d.assign(V, inf);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top(); que.pop();
        ll v = p.second;
        if (d[v] < p.first) continue;
        for (edge e : G[v]) {
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

ll dfs(ll v) {
    if (d[v] != -inf) return d[v];
    ll ret = -1;
    vec ord;
    for (auto nv : G[v]) {
        ord.push_back(dfs(nv.to));
    }
    sort(ord.begin(), ord.end());
    ll n = ord.size();
    Rep (i, n) {
        chmax(ret, ord[i]+n-1-i);
    }
    d[v] = ret + 1;
    return d[v];
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    G.assign(N, vector<edge>());
    d.assign(N, -inf);
    for (ll i = 1; i < N; i++) {
        ll a;
        cin >> a;
        a--;
        G[a].push_back({i, 1});
    }

    dfs(0);

    // Rep (i, N) {
    //     cout << d[i] << " \n"[i==N-1];
    // }

    cout << dfs(0) << "\n";
    return 0;
}