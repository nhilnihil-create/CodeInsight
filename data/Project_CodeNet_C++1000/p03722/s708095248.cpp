#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

template <class T> inline bool chmax(T &a, const T &b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <class T> inline bool chmin(T &a, const T &b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

struct edge {
    ll from, to, cost;
};

ll n, m, d[1009];

vector<edge> e;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m;
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        e.push_back({a, b, -c});
    }
    fill(d, d + 1009, 1e18);
    d[1] = 0;
    rep(i, n - 1) rep(j, m) chmin(d[e[j].to], d[e[j].from] + e[j].cost);
    bool inf[1009] = {};
    rep(i, n) rep(j, m) {
        if(d[e[j].to] > d[e[j].from] + e[j].cost) {
            d[e[j].to] = d[e[j].from] + e[j].cost;
            inf[e[j].to] = true;
        }
        inf[e[j].to] |= inf[e[j].from];
    }
    inf[n] ? cout << "inf" : cout << -d[n];
}