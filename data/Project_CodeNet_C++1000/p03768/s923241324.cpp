#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
ll MOD=998244353;
#define INF 2*1e9
#define N 1000010
#define MAX_V 900010
using namespace std;

struct draw{
    int d,color,when;
};
int n,m,q;
vector<int> G[N];
pii p[N][12];
void bfs(){
    rep2(i,1,n){
        for(int k=10;k>=0;k--){
            rep(j,G[i].size()){
                if(p[i][k].second<p[G[i][j]][k+1].second){
                    p[i][k]=p[G[i][j]][k+1];
                }
            }
            if(p[i][k+1].second>p[i][k].second){
                p[i][k]=p[i][k+1];
            }
        }
    }
}
main(){
    cin>>n>>m;
    rep(i,m){
        int f,t;
        cin>>f>>t;
        G[f].pb(t);G[t].pb(f);
    }
    cin>>q;
    rep2(i,1,q){
        int v,d,c;cin>>v>>d>>c;
        p[v][d]={c,i};
    }
    rep(i,11)bfs();
    rep2(i,1,n){
        cout<<p[i][0].first<<endl;
    }
}