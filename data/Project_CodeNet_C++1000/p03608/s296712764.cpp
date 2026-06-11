#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

vector<vector<ll>> d;
//ll ans = LINF;
//
//void rec(ll start, map<ll, ll> done, ll sum) {
//    for (auto town : done) {
//        if (town.second == 1) continue;
//
//        done[town.first] = 1;
//        rec(town.first, done, sum += d[start][town.first]);
//        done[town.first] = 0;
//    }
//
//    ans = min(ans, sum);
//};

int main() {

    ll n, m, r; cin >> n >> m >> r;
    vector<ll> t(r);
    for (ll i = 0; i < r; ++i) {
        cin >> t[i];
        t[i]--;
    }

    d.resize(n, vector<ll>(n, LINF));
    for (int i = 0; i < n; ++i) {
        d[i][i] = 0;
    }
    for (ll i = 0; i < m; ++i) {
        ll a, b, c; cin >> a >> b >> c;
        --a; --b;

        d[a][b] = c;
        d[b][a] = c;
    }

    // ワーシャルフロイド
    for (ll k = 0; k < n; ++k) {
        for (ll i = 0; i < n; ++i) {
            for (ll j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

//    map<ll, ll> done;
//    for (ll i = 0; i < r; ++i) {
//        done[t[i]] = 0;
//    }
//
//    for (ll i = 0; i < r; ++i) {
//        done[t[i]] = 1;
//        rec(t[i], done, 0);
//        done[t[i]] = 0;
//    }

    ll ans = LINF;
    sort(t.begin(), t.end());
    do {
        ll tmp = 0;
        for (int i = 1; i < t.size(); ++i) tmp += d[t[i-1]][t[i]];
        ans = min(ans, tmp);
    } while (next_permutation(t.begin(), t.end()));

    cout << ans << endl;
}