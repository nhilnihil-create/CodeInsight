#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;

int n, m, q;
const int maxn = 1e5 + 5;
vector<int> G[maxn];

int d[maxn], z[maxn], c[maxn];
int col[maxn];

bool vis[maxn][15];

void dfs(int u, int dis, int color){
    if(vis[u][dis])
        return;
    vis[u][dis] = true;
    if(col[u] == 0){
        col[u] = color;
    }
    if(dis == 0){
        return;
    }
    for(auto v : G[u]){
        dfs(v, dis - 1, color);
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cin >> q;
    for(int i = 1;i <= q;i++){
        cin >> z[i] >> d[i] >> c[i];
    }
    for(int i = q;i >= 1;i--){
        dfs(z[i], d[i], c[i]);
    }
    for(int i = 1;i <= n;i++){
        cout << col[i] << endl;
    }
    return 0;
}
