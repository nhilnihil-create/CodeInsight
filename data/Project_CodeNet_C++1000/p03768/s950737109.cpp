#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 1e5 + 7;
int n, m, q;
vector <ii> ed;
const int K = 11;
int dp[N][K], color[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m;
    while (m--) {
        int u, v; cin >> u >> v;
        ed.app({u, v}); ed.app({v, u});
    }   
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int u, d, c;
        cin >> u >> d >> color[i];
        dp[u][d] = i;
    }   
    for (int t = 0; t < K * 2; ++t) {
        for (auto e : ed) {
            for (int d = 1; d < K; ++d) {
                dp[e.s][d - 1] = max(dp[e.s][d - 1], dp[e.f][d]);
            }   
        }   
    }   
    for (int i = 1; i <= n; ++i) {
        int ans = 0;
        for (int j = 0; j < K; ++j) ans = max(ans, dp[i][j]);
        cout << color[ans] << '\n';
    }   
}   