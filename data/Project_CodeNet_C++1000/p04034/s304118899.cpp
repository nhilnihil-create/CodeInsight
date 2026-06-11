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
bool can[N];
int cnt[N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cnt[i] = 1;
    }   
    can[1] = 1;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        can[v] |= can[u];
        --cnt[u];
        ++cnt[v];
        if (cnt[u] == 0)
            can[u] = 0;
    }   
    /*
    for (int i = 1; i <= n; ++i) {
        cout << cnt[i] << ' ' << can[i] << endl;
    }   
    */
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += can[i];
    }   
    cout << ans << endl;
}