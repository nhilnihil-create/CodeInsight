#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repr(i, n) for (ll i = n; i >= 0; i--)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define INIT    \
    cin.tie(0); \
    ios::sync_with_stdio(false);

template <class T>
inline bool chmax(T& a, T b) {
    return a = (a < b) ? b : a;
}
template <class T>
inline bool chmin(T& a, T b) {
    return a = (a > b) ? b : a;
}

ll const INF = 1LL << 60;
ll const MOD = 1000000007;

ll const MAX_V = 1000000;

struct edge {
    ll to, cost;
};
vector<edge> G[MAX_V];

ll d[MAX_V];  // 距離計算

void dfs(ll v, ll p, ll c) {
    d[v] = c;

    for (auto nv : G[v]) {
        if (nv.to == p) continue;  // nv が親 p だったらダメ
        dfs(nv.to, v, c + nv.cost);
    }
}

int main() {
    INIT;
    ll N;
    cin >> N;

    for (ll i = 0; i < N - 1; i++) {
        ll s, t, c;
        cin >> s >> t >> c;
        s--;
        t--;
        edge et = {t, c};
        G[s].push_back(et);

        edge es = {s, c};
        G[t].push_back(es);
    }

    ll Q, K;
    cin >> Q >> K;
    K--;
    vector<ll> x(Q), y(Q);
    rep(i, Q) {
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
    }

    dfs(K, -1, 0LL);
    // dijkstra(K, N);
    // for (ll i = 0; i < N; i++) cout << i << ": " << d[i] << endl;

    rep(i, Q) { cout << d[x[i]] + d[y[i]] << endl; }

    return 0;
}