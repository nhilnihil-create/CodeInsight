#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007LL;
const int INF = LLONG_MAX;

int dfs(int cur, int tmp, vector<vector<int> > &G, int d, vector<bool> &used, int u, int v){

    used[cur] = true;
    int ret = 0;
    for(auto nxt : G[cur]){
        if(!used[nxt]){
            if(cur == u && nxt == v) continue;
            if(cur == v && nxt == u) continue;
            ret += dfs(nxt, tmp + 1, G, d, used, u, v);
        }
    }

    if(d < tmp) ret++;
    return ret;
}

signed main(){
    
    int n, k; cin >> n >> k;
    vector<vector<int> > G(n + 1);
    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int ans = INF;
    if(k % 2 == 0){
        for(int i = 0; i < n; i++){
            vector<bool> used(n, false);
            ans = min(ans, dfs(i, 0, G, k / 2, used, -1, -1));            
        }    
    }else{
        for(int i = 0; i < n; i++){
            for(auto j : G[i]){
                G[n].push_back(i);
                G[n].push_back(j);
                vector<bool> used(n, false);            
                ans = min(ans, dfs(n, 0, G, (k + 1) / 2, used, i, j));
                G[n].erase(G[n].begin(), G[n].end());
            }
        }
    }

    cout << ans << endl;
    return 0;
}
