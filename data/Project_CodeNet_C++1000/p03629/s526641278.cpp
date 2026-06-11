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

int main(void) {
    string s;
    cin >> s;
    const ll n = s.size();

    vector<ll> v(26, n);
    vector<vector<ll>> next(n+1, vector<ll>(26, n));
    for(ll i=n-1; i>=0; --i) {
        v[s[i]-'a'] = i;
        next[i] = v;
    }

    vector<pair<char,ll>> rec(n+1, {'$', n});
    vector<ll> dp(n+1, INF);
    dp[n] = 1;
    for(ll i=n-1; i>=0; --i) {
        REP(j, 26) {
            if(next[i][j] == n) {
                if(dp[i] > 1) {
                    dp[i] = 1;
                    rec[i] = {'a'+j, n};
                }
            } else {
                if(dp[i] > dp[next[i][j]+1]+1) {
                    dp[i] = dp[next[i][j]+1]+1;
                    rec[i] = {'a'+j, next[i][j]+1};
                }
            }
        }
    }

    string ans = "";
    ll idx = 0;
    while(idx < n) {
        ans += rec[idx].first;
        idx = rec[idx].second;
    }
    cout << ans << endl;

    return 0;
}