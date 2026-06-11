#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;

ll d[222][222];
bool seen[10];
ll an=1e9,sum=0,r;
ll R[10];


void dfs(int i,ll len=1){
    if(len==r)an=min(an,sum);
    seen[i]=1;
    rep(j,0,r){
        if(seen[j])continue;
        seen[j]=1;
        sum+=d[R[i]][R[j]];
        dfs(j,len+1);
        seen[j]=0;
        sum-=d[R[i]][R[j]];
    }
    seen[i]=0;
}

int main(){
    ll n,m;cin>>n>>m>>r;
    rep(i,0,r){cin>>R[i];R[i]--;}
    rep(i,0,n)rep(j,0,n)d[i][j]=1e9;
    rep(i,0,n)d[i][i]=0;
    rep(i,0,m){
        ll a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        d[a][b]=c;
        d[b][a]=c;
    }
    rep(k,0,n){
        rep(i,0,n){
            rep(j,0,n){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    rep(i,0,r){
        sum=0;
        dfs(i);
    }
    cout<<an<<endl;
}
    







