#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define ARRAY_LENGTH(array) sizeof(array)/sizeof(*array)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const int INF = 1000100100;

using Graph = vector<vector<ll>>;
Graph G;

vector<ll> memo(1e6 + 1, INF);
vector<bool> pressed(1e6 + 1, false);

ll min_cnt(ll from, ll cnt) {
    if(from == 1) {
        return cnt;
    }

    if(memo[from] != INF) {
        return memo[from];
    }

    if(G.at(from).empty() || pressed[from]) {
        memo[from] = -1;
    } else {
        pressed[from] = true;

        ll res = INF;
        REP(i, G.at(from).size()) {
            ll n_from = G[from][i];
            ll tmp = min_cnt(n_from, cnt + 1);
            if(tmp != -1) {
                res = min(res, tmp);
            }
        }

        if(res == INF) {
            memo[from] = -1;
        } else {
            memo[from] = res;
        }
    }

    if(memo[from] == -1) {
        pressed[from] = true;
    }

    return memo[from];
}

int main() {
    ll N;
    cin >> N;

    G.resize(N + 1);
    REP(i, N) {
        ll a;
        cin >> a;
        G.at(i).emplace_back(a - 1);
    }

    ll ans = min_cnt(0, 0);
    cout << ans << endl;

    return 0;
}