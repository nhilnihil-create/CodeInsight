#include <iostream>
#include <vector>
#define maxn 100005
#define mp make_pair
#define fi first
#define se second
using namespace std;
vector <int> G[maxn];
pair <int, int> e[maxn];
int dfs(int u, int f, int d, int lim){
    int cnt = d > lim;
    for (int i = 0; i < G[u].size(); ++ i){
        int v = G[u][i];
        if (v != f)
            cnt += dfs(v, u, d + 1, lim);
    }
    return cnt;
}
int main(){
    int n, k;
    cin >> n >> k;
    for (int i = 1; i < n; ++ i){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        e[i] = mp(u, v);
    }
    if (k % 2 == 0){
        int ans = n;
        for (int i = 1; i <= n; ++ i)
            ans = min(ans, dfs(i, 0, 0, k / 2));
        cout << ans << endl;
        return 0;
    }
    else{
        int ans = n;
        for (int i = 1; i < n; ++ i)
            ans = min(ans, dfs(e[i].fi, e[i].se, 0, (k - 1) / 2) + dfs(e[i].se, e[i].fi, 0, (k - 1) / 2));
        cout << ans << endl;
    }
    return 0;
}
