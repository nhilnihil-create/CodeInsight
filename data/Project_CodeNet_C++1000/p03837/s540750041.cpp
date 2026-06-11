#include <bits/stdc++.h>
#define MAXN 110
#define pii  pair<int, int>
#define pll  pair<long long, long long>
#define ss second
#define ff first
 
using ll = long long;
using namespace std;
const int mod = 1e9 + 7;
int adj[MAXN][MAXN];

void solve(int n){
    for (int k=1; k<=n; k++){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                adj[i][j] = min(adj[i][k] + adj[k][j], adj[i][j]);
            }
        }
    }
}

void init(int n){
    for (int i=0; i<=n; i++){
        for (int j=0; j<=n; j++){
            adj[i][j] = mod;
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    init(n);
    vector<pair<int, pii>> edge(m);

    for (int i=0; i<m; i++){
        cin >> edge[i].ss.ff >> edge[i].ss.ss >> edge[i].ff;
        adj[edge[i].ss.ff][edge[i].ss.ss] = adj[edge[i].ss.ss][edge[i].ss.ff] = edge[i].ff;
    }

    solve(n);

    int ans = 0;

    for (int i=0; i<m; i++){
        int x = edge[i].ss.ff, y = edge[i].ss.ss, c = edge[i].ff;
        if (adj[x][y] != c) ans++;
    }

    cout << ans << endl;
    return 0;
}