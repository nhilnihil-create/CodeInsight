
#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const ll INF=1e10;
int main(){
    int n;
    cin>>n;
    vector<vector<ll>> a(n,vector<ll>(n));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>a[i][j];

    vector<vector<ll>> d(n,vector<ll>(n,INF));
    for(int i=0;i<n;i++) d[i][i]=0;
    using Edge=pair<ll,pair<int,int>>;
    vector<Edge> edges;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            edges.push_back({a[i][j],{j,i}});
        }
    }
    sort(edges.begin(),edges.end());
    ll res=0;
    for(auto &e:edges){
        ll len=0;        
        int u,v;
        len=e.first;
        u=e.second.first,v=e.second.second;
        if(len<d[u][v]){
            d[u][v]=d[v][u]=len;
            res+=len;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    d[i][j]=min(d[i][j],d[i][u]+d[u][v]+d[v][j]);
                    d[i][j]=min(d[i][j],d[i][v]+d[v][u]+d[u][j]);
                    d[j][i]=d[i][j];
                }
            }
            
        }
    }
    cout<<(d==a ? res : -1LL)<<endl;
    
    return 0;
}