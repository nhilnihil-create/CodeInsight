#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
template<typename T> void chmin(T &a, const T &b) { a = min(a, b); }
template<typename T> void chmax(T &a, const T &b) { a = max(a, b); }
struct FastIO {FastIO() { cin.tie(0); ios::sync_with_stdio(0); }}fastiofastio;
#ifdef DEBUG_ 
#include "../program_contest_library/memo/dump.hpp"
#else
#define dump(...)
#endif
const ll INF = 1LL<<60;

struct BIT {
    int n;
    vector<ll> bit;
    BIT(int sz) { 
        n=1; while(n < sz) n*=2;
        bit.assign(n+1, 0); 
    }
    void update(int i, ll w) {
        for(int x=i+1; x<(int)bit.size(); x += x&-x) bit[x] += w;
    }
    // [0,i]
    ll query(int i) {
        ll ret = 0;
        for(int x=i+1; x>0; x -= x&-x) ret += bit[x];
        return ret;
    }
};

int main(void) {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll,PII>> p(n);
    REP(i, n) {
        cin >> p[i].second.first >> p[i].second.second;
        p[i].first = p[i].second.second - p[i].second.first + 1;
    }
    sort(ALL(p));
    vector<ll> l(n), r(n);
    REP(i, n) l[i] = p[i].second.first, r[i] = p[i].second.second;

    BIT bit(m+1);
    ll num = n, idx = 0;
    FOR(d, 1, m+1) {
        // 区間長がd未満のものの分を加算
        while(idx < n && r[idx]-l[idx]+1 < d) {
            bit.update(l[idx], 1);
            if(r[idx]+1<=m) bit.update(r[idx]+1, -1);
            idx++;
            num--;
        }
        // bitでdの倍数を参照
        ll ret = 0;
        for(ll i=d; i<=m; i+=d) ret += bit.query(i);
        cout << ret + num << "\n";
    }
    cout << flush;

    return 0;
}