#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"

vector<vector<ll>> g;
vector<ll> dp;

ll dfs(ll v = 0) {
    if (dp[v] != -1) return dp[v];
    vector<ll> s;
    for(auto &x : g[v]) {
        s.push_back(dfs(x));
    }
    sort(rall(s));
    dp[v] = sz(s);
    rep(i, sz(s)) {
        dp[v] = max(dp[v], s[i] + i);
    }
    return dp[v] + 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll n;
    cin >> n;
    g.resize(n);
    rep(i, n - 1) {
        ll a;
        cin >> a;
        g[a - 1].push_back(i + 1);
    }
    dp.resize(n, -1);
    cout << (dfs(0) - 1) << endl;
    return 0;
}
