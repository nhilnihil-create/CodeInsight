#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>>g(n);
    rep(i,m) {
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int>dist(n,-1);
    dist[0] = 0;
    queue<int>q;
    q.push(0);
    while(!q.empty()) {
        int v = q.front();q.pop();
        for(auto nv : g[v]) {
            if(dist[nv] == -1) {
                dist[nv] = dist[v]+1;
                q.push(nv);
            }
        }
    }
    if(dist[n-1] == 2) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
}