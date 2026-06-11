#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define fi first
#define se second

#define all(x) (x).begin(), (x).end()

typedef long long ll;

using namespace std;             
const int N = (int) 1e5 + 5;

int n, a[N];

vector<int> g[N];

void dfs(int v, int pr) {
    if (g[v].size() == 1)return;
    
    ll sum = 0;
    int mx = 0;

    for (int to : g[v]) {
        if (to == pr) continue;                                                                                                 
        dfs(to, v);
        sum += a[to];
        mx = max(mx, a[to]);
    }

    if (a[v] > sum || sum > 2 * a[v]) {
        cout << "NO\n";
        exit(0);
    }

    int k = sum - a[v];
    if (k > sum - mx) {
        cout << "NO\n";
        exit(0);
    }

    a[v] -= k;

    return;
}


void solve() {    
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        int l, r;
        cin >> l >> r;
        g[l].pb(r);
        g[r].pb(l);
    }

    if (n == 2) {
        if (a[1] == a[2]) {
            cout << "YES\n";
        }
        else cout << "NO\n";
        return;
    }

    int v = 1;
    while (g[v].size() == 1) {
        v++;
    }
    
    dfs(v, -1);
      
    if (a[v] == 0) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
      
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int tt = 1;

    while (tt--) {
        solve();
    }

    return 0;
}