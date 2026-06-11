#include <bits/stdc++.h>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)
#define rep(i, n) repd(i, 0, n)

using namespace std;

using ll = long long;
using ul = unsigned long long;
using ld = long double;
ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> g(n);
    repd(i, 1, n) {
        ll p;
        cin >> p;
        p--;
        g[p].push_back(i);
    }

    auto dfs = [&](auto self, ll v) -> ll {
        ll ans = 0;
        vector<ll> temp;
        if (g[v].size() == 0) {
            return 0;
        }

        for (auto u : g[v]) {
            temp.push_back(self(self, u));
        }
        sort(temp.begin(), temp.end(), greater<ll>());
        rep(i, temp.size()) { ans = max(ans, temp[i] + i + 1); }
        return ans;
    };

    cout << dfs(dfs, 0) << endl;
    return 0;
}

