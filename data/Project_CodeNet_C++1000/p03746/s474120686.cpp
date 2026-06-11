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
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bool visited[n] = {};
    vector<ll> path0, path1;
    visited[0] = true;
    path0.push_back(0);
    ll now = 0;
    while (true) {
        bool flag = false;
        for (ll next : g[now]) {
            if (visited[next]) {
                continue;
            }
            flag = true;
            path0.push_back(next);
            visited[next] = true;
            now = next;
            break;
        }
        if (!flag) {
            break;
        }
    }

    path1.push_back(0);
    now = 0;
    while (true) {
        bool flag = false;
        for (ll next : g[now]) {
            if (visited[next]) {
                continue;
            }
            flag = true;
            path1.push_back(next);
            visited[next] = true;
            now = next;
            break;
        }
        if (!flag) {
            break;
        }
    }

    if (path1.size() == 1) {
        ll len = path0.size();
        cout << len << endl;
        rep(i, len) { cout << path0[i] + 1 << " "; }
        cout << endl;
    } else {
        ll len0 = path0.size(), len1 = path1.size();
        cout << len0 + len1 - 1 << endl;
        repb(i, len1) { cout << path1[i] + 1 << " "; }
        repd(i, 1, len0) { cout << path0[i] + 1 << " "; }
        cout << endl;
    }
    return 0;
}

