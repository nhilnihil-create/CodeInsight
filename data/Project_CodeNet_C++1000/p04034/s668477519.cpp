#define MOD 998244353
#define  endll  "\n"
#define  ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pll pair<ll,ll>

#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 7, M = 2 * N, SEGN = 2 << (32 - __builtin_clz(N));
int n, m;
int cur[N];
bool ever[N], may[N];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input", "rt", stdin);
    //  freopen("output", "wt", stdout);
#endif
    may[1]  = 1;
    cin >> n >> m;
    fill(cur,cur+n+1,1);


    for (int i = 0; i < m; i++) {
        int t, f;
        cin >> t >> f;
        cur[f]++, cur[t]--;
        if (!may[f] && may[t]) may[f] = 1;
        if (cur[t] == 0) may[t] = 0;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        if (may[i])ans++;
    cout << ans;
}