#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MAX = 2e5+1;

bool ok = true;
vector<vector<int>> g;
vector<ll> a;

ll go(int u, int p) {
    ll sum = 0;
    bool leaf = true;
    vector<ll> d(g[u].size());
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(v != p) {
            leaf = false;
            d[i] = go(v, u);
            sum += d[i];
        }
    }
//    cout << u << " - " << sum << endl;
    if(leaf || (p == -1 && g[u].size() == 1)) {
        if(p == -1) ok &= sum == a[u];
        return a[u];
    }
    ll r = 2*a[u] - sum;
//    cout << u << " " << r << " " << sum << endl;
    if(p != -1) ok &= r >= 0;
    if(p != -1) sum += r;
    ok &= sum == 2*a[u];
    ok &= sum % 2 == 0;
    for(int i = 0; i < g[u].size(); i++) {
        ok &= d[i] <= sum/2;
    }
    ok &= r <= sum/2;
    return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif

    int n; cin >> n;
    g.assign(n+1, vector<int>());
    a.assign(n+1, 0);

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    go(1, -1);

    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;

}
