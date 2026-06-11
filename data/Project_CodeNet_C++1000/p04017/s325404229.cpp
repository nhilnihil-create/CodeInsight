#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
struct FastIO {FastIO() { cin.tie(0); ios::sync_with_stdio(0); }}fastiofastio;
#ifdef DEBUG
#include "../program_contest_library/memo/dump.hpp"
#else
#define dump(...)
#endif
const ll INF = 1LL<<60;

template<ll LOG=60>
struct doubling {
    // nxt[i][j] = (j番目の要素に関数fを2^i回適用した要素は何番目の要素か)
    vector<vector<ll>> nxt; 
    doubling(vector<ll> nxt0) : nxt(LOG, vector<ll>(nxt0.size())) {
        REP(i, nxt0.size()) nxt[0][i] = nxt0[i];
        FOR(k, 1, LOG) REP(j, nxt0.size()) nxt[k][j] = nxt[k-1][nxt[k-1][j]];
    }
    // x番目の要素に関数fをk回適用した要素は何番目の要素か？
    ll query(ll x, ll k) {
        for(ll i=LOG-1; i>=0; --i) if(k&1LL<<i) x = nxt[i][x];
        return x;
    }
};

int main() {
    ll n;
    cin >> n;
    vector<ll> x(n);
    REP(i, n) cin >> x[i];
    ll l;
    cin >> l;

    // x[j] <= x[idx] + l であるような最大のj に移動できる
    vector<ll> nxt0(n);
    REP(i, n) nxt0[i] = upper_bound(ALL(x), x[i]+l) - x.begin() - 1;
    doubling<60> dbl(nxt0);

    ll q;
    cin >> q;
    while(q--) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        if(a > b) swap(a, b);

        ll ret = 0;
        for(ll i=59; i>=0; --i) {
            if(dbl.nxt[i][a] < b) {
                ret += 1LL<<i;
                a = dbl.nxt[i][a];
            }
            if(dbl.nxt[0][a] >= b) {
                ret++;
                break;
            } 
        }
        cout << ret << endl;
    }

    return 0;
}
