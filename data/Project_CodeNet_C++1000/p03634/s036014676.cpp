#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<vector<P> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int n;
Graph G;
ll dist[100010];

void dfs(int v,int p,ll c){
    dist[v]=dist[p]+c;
    for(auto x:G[v]){
        int nx=x.first;
        int nc=x.second;
        if(nx==p)continue;
        dfs(nx,v,nc);
    }
}
int main(){
    cin >> n;
    G.resize(n);
    rep(i,n-1){
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        G[a].push_back(make_pair(b,c));
        G[b].push_back(make_pair(a,c));
    }
    int q,k;
    cin >> q >> k;
    k--;
    rep(i,n){
        dist[i]=0;
    }
    dist[-1]=0;
    dfs(k,-1,0);
    rep(i,q){
        int x,y;
        cin >> x >> y;
        x--;y--;
        ll ans = dist[x]+dist[y];
        cout << ans << endl;
    }
    return 0;
}