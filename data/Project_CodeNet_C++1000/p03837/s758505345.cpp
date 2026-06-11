#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';

const int N = 101, INF = 1e9;
int f[N][N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (i != j) 
                f[i][j] = INF;

    vector <vector <int> > ed;
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        ed.app({u, v, c});
        f[u][v] = f[v][u] = c;
    }   

    for (int k = 1; k <= n; ++k)
        for (int u = 1; u <= n; ++u)
            for (int v = 1; v <= n; ++v)
                f[u][v] = min(f[u][v], f[u][k] + f[k][v]);

    int ans = 0;
    for (auto e : ed) {
        int u = e[0], v = e[1], c = e[2];

        bool us = 0;
        for (int s = 1; s <= n; ++s)
            for (int t = 1; t <= n; ++t)
                us |= f[s][u] + c + f[v][t] == f[s][t];
        ans += !us;
        
    }   
    cout << ans << endl;
}
