#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const ll MAXN = 1e5+5;
 
ll n, a[MAXN], val[MAXN];
vector<ll> g[MAXN];
 
void dfs(ll v, ll f = -1) {
    ll ct = 0;
    for (ll u : g[v]) {
        if (u == f)
            continue;
        ct++;
        dfs(u, v);
    }
 
    if (ct == 0) {
        val[v] = a[v];
        return;
    }
 
    vector<ll> w;
    for (ll u : g[v]) {
        if (u == f)
            continue;
        w.push_back(val[u]);
    }
    sort(w.begin(), w.end());
    ll sum = 0, sum1 = 0;
    for (ll i = 0; i < w.size(); ++i) {
        sum += w[i];
        if (i == w.size()-1) {
            sum1 = sum;
            sum1 -= w[i];
        }
    }
 
    ll m = sum - a[v];
    if (m < 0 || m > sum1) {
        cout << "NO\n";
        exit(0);
    } if (a[v] - m < 0) {
        cout << "NO\n";
        exit(0);
    }
 
    val[v] = a[v] - m;
}
 
int main() {
    cin >> n;
    for (ll i = 0; i < n; ++i)
        cin >> a[i];
 
    for (ll i = 0; i < n-1; ++i) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
 
    if (n == 2) {
        if (a[0] == a[1]) {
            cout << "YES\n";
        } else
            cout << "NO\n";
        return 0;
    }
 
    for (ll i = 0; i < n; ++i) {
        if (g[i].size() > 1) {
            dfs(i);
            if (val[i] == 0) {
                cout << "YES\n";
            } else
                cout << "NO\n";
            return 0;
        }
    }
}