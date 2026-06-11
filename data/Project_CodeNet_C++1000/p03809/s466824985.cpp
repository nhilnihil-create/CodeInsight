#include<bits/stdc++.h>

using namespace std;
using ll = long long int;
#define long ll

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i=0; i<n; i++)
        cin >> a[i];

    vector<vector<ll>> G(n);
    for(ll i=0; i<n-1; i++) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    ll l;
    {
        auto dfs = [&](auto dfs, ll cur, ll pre) -> void {
            if(G[cur].size() == 1) l = cur;
            for(auto &v: G[cur]) {
                if(v == pre) continue;
                dfs(dfs, v, cur);
            }
        };
        dfs(dfs, 0, -1);
    }

    bool ok = true;
    auto dfs = [&](auto dfs, ll cur, ll pre) -> ll {
        ll s = 0;
        vector<ll> sub;
        for(ll v: G[cur]) {
            if(v == pre) continue;
            ll r = dfs(dfs, v, cur);
            s += r;
            sub.push_back(r);
        }
        if(s == 0) return a[cur];

        ll x = s - a[cur];
        if(x < 0) ok = false;

        ll t = sub[0], v = 0;
        for(ll i=1; i<sub.size(); i++)
            v += min(t, sub[i]), t = abs(t - sub[i]);
        if(x > v) ok = false;
        return s - 2*x;
    };
    if(dfs(dfs, l, -1) == a[l] && ok)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
