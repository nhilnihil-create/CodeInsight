#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n, m; 
    cin >> n >> m;
    vector<vector<int>> G(n);
    rep(i,m){
        int a, b; 
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> dist(n, -1);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto nv : G[v]){
            if(dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            q.push(nv);
        }
    }
    //for(auto p : dist) cout << p << endl;
    if(dist[n-1] == 2) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl; 
}