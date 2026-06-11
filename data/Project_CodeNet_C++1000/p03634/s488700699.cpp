#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll n;cin>>n;
    vector<vector<pair<ll,ll>>> t(n);
    rep(i,n-1){
        int a,b;ll c;cin>>a>>b>>c;a--;b--;
        t[a].push_back({b,c});
        t[b].push_back({a,c});
    }
    int q,k;cin>>q>>k;k--;
    priority_queue<pair<ll,int>> que;
    que.push({0,k});
    vector<bool> used(n,false);
    vector<ll> d(n,1e+18);
    d[k]=0;
    while(que.size()){
        int v=que.top().second;que.pop(); 
        used[v]=true;
        rep(i,t[v].size()){
            int y=t[v][i].first;ll c=t[v][i].second;
            if(chmin(d[y],d[v]+c))que.push({d[y],y});
        }
    }
    rep(i,q){
        int x,y;cin>>x>>y;x--;y--;
        ll res=d[x]+d[y];
        cout<<res<<endl;
    }
}