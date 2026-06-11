#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using ll=long long;

int main(){
    ll n,m,r;
    cin>>n>>m>>r;
    vector<ll> vis(r);
    for(int i=0;i<r;i++){
        cin>>vis[i];
        vis[i]--;
    }
    sort(vis.begin(),vis.end());
    vector<vector<ll>> dat(n,vector<ll>(n,1e9));
    rep(i,m){
        ll a,b,c;
        cin>>a>>b>>c;a--;b--;
        if(dat[a][b]==1e9){
            dat[a][b]=dat[b][a]=c;
        }
        else{
            dat[a][b]=dat[b][a]=min(dat[a][b],c);
        }
    }
    rep(k,n){
        rep(i,n){
            rep(j,n){
                dat[i][j]=min(dat[i][j],dat[i][k]+dat[k][j]);
            }
        }
    }
    ll ans=INT_MAX;
    do{
        ll sum=0;
        rep(i,r-1){
            sum+=dat[vis[i]][vis[i+1]];
        }
        ans=min(ans,sum);
    }while(next_permutation(vis.begin(),vis.end()));
    cout<<ans<<endl;
    return 0;
}