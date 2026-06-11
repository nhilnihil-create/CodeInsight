#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;

int n, k, ans;
vector<int> dist;
vector<vector<int>> G;


void dfs(int v, int p = -1){
    for(auto nv : G[v]){
        if(nv == p) continue;
        dfs(nv, v);
        if(dist[nv] == k-1) if(p != -1) { ans++; continue; }
        if(dist[nv]+1 > dist[v]) dist[v] = dist[nv]+1;
    }
}

int main(){
    cin >> n >> k;
    G.assign(n,vector<int>());
    rep(i,n){
        int a; cin >> a; a--;
        if(i == 0){ if(a != 0) ans++; continue; }
        G[a].push_back(i);
    }
    dist.assign(n,0);
    dfs(0);
    cout << ans << endl;
}