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
#ifdef DEBUG
#include "../program_contest_library/memo/dump.hpp"
#else
#define dump(...)
#endif
const ll INF = 1LL<<60;

int main(void) {
    ll n, x;
    cin >> n >> x;

    // map<ll,vector<ll>> mp;
    // vector<ll> ord(2*n-1);
    // iota(ALL(ord), 1);
    // do {
    //     vector<ll> a(ord);
    //     for(ll len=2*n-3; len>=1; len-=2) {
    //         vector<ll> na(len);
    //         auto get = [](ll p, ll q, ll r) { 
    //             ll mi = min({p, q, r}), ma = max({p, q, r});
    //             if(p != mi && p != ma) return p;
    //             if(q != mi && q != ma) return q;
    //             return r;
    //         };
    //         REP(i, len) na[i] = get(a[i], a[i+1], a[i+2]);
    //         a = move(na);
    //     }
    //     mp[a[0]] = ord;
    // } while(next_permutation(ALL(ord)));

    // dump(mp);

    if(x == 1 || x == 2*n-1) {
        cout << "No\n";
        return 0;
    }

    if(n == 2) {
        cout << "Yes\n";
        cout << "1\n2\n3\n";
        return 0;
    }

    vector<ll> ans(2*n-1);
    vector<bool> used(2*n-1);
    if(x+2 <= 2*n-1) {
        ans[n-2] = x+2;
        ans[n-1] = x;
        ans[n]   = 1;
        ans[n+1] = x+1;
        used[0] = used[x-1] = used[x] = used[x+1] = true;
    } else {
        ans[n-2] = x-2;
        ans[n-1] = x;
        ans[n]   = 2*n-1;
        ans[n+1] = x-1;
        used[x-3] = used[x-2] = used[x-1] = used[2*n-2] = true;
    }

    ll idx = 0;
    REP(i, n-2) {
        while(idx<2*n-1 && used[idx]) idx++;
        ans[i] = idx+1;
        used[idx] = true;
    }
    FOR(i, n+2, 2*n-1) {
        while(idx<2*n-1 && used[idx]) idx++;
        ans[i] = idx+1;
        used[idx] = true;
    }

    cout << "Yes\n";
    REP(i, 2*n-1) cout << ans[i] << "\n";

    return 0;
}