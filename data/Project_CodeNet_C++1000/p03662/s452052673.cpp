#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
typedef long long ll;
int main(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    rep(i,n-1){
        int a,b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> df(n, -1), ds(n, -1);
    df[0] = 0; ds[n-1] = 0;
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int u = que.front(); que.pop();
        for(int v : g[u]){
            if(df[v] != -1) continue;
            df[v] = df[u] + 1;
            que.push(v);
        }
    }
    que.push(n-1);
    while(!que.empty()){
        int u = que.front(); que.pop();
        for(int v : g[u]){
            if(ds[v] != -1) continue;
            ds[v] = ds[u] + 1;
            que.push(v);
        }
    }
    int cf = 0, cs = 0;
    FOR(i,1,n-1){
        if(ds[i] < df[i]) cs++;
        else cf++;
    }
    if(cs < cf) cout << "Fennec" << endl;
    else cout << "Snuke" << endl;
}