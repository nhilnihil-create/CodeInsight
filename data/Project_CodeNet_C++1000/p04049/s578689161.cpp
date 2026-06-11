#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define int ll
#define pw(x) (1LL<<(x))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define SZ(a) ((int)(a).size())
#define dbg(a) cerr << #a << " = " << a << '\n'

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;

void open(string file) {
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
}

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

const int N = 2e3 + 17;

int n, k;
vector<int> g[N];
int good[N], h[N];

void dfs(int v, int p = -1) {
    if (p == -1) h[v] = 0;
    good[v] = 0;
    if (h[v] == k / 2 + 1) good[v]++;
    for (auto to : g[v]) {
        if (to != p) {
            h[to] = h[v] + 1;
            dfs(to, v);
            good[v] += good[to];
        }
    }
}

signed main() {
    //open("cbarn");
    fast_io();
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    if (k % 2 == 0) {
        int ans = n;
        for (int i = 1; i <= n; i++) {
            dfs(i);
            int cnt = 0;
            for (int j = 1; j <= n; j++) {
                if (h[j] <= k / 2) cnt++;
            }
            ans = min(ans, n - cnt);
        }
        cout << ans;
    } else {
        int ans = n;
        for (int i = 1; i <= n; i++) {
            dfs(i);
            int cnt = 0;
            for (int j = 1; j <= n; j++) {
                if (h[j] <= k / 2) cnt++;
            }
            int mx = 0;
            for (auto to : g[i]) mx = max(mx, good[to]);
            cnt += mx;
            ans = min(ans, n - cnt);
        }
        cout << ans;
    }
    return 0;
}
