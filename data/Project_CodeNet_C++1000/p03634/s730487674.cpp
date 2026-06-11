#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    map<P,int> mp;
    rep(i,n-1){
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
        mp[P(a,b)] = c;
        mp[P(b,a)] = c;
    }
    int q, k;
    cin >> q >> k;
    k--;

    queue<int> que;
    vector<ll> dist(n, -1);

    dist[k] = 0;
    que.push(k);
    while(!que.empty()){
        int v = que.front();
        que.pop();

        for(int nv : g[v]){
            if(dist[nv] != -1) continue;
            dist[nv] = dist[v] + mp[P(v,nv)];
            que.push(nv);
        }
    }

    rep(i,q){
        int x, y;
        cin >> x >> y;
        x--, y--;
        cout << dist[x] + dist[y] << endl;
    }
}