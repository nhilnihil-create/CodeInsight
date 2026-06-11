#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
int main(){
    ll n,T[200001],A[200001],D[200001][2],ans=1,mod=1e9+7;
    cin>>n;
    rep(i,n) cin>>T[i];
    rep(i,n) cin>>A[i];
    if(T[n-1]!=A[0]) ans=0;
    int t,a;
    rep(i,n) if(T[i]==A[0]){
        t=i;
        break;
    }
    rep(i,n) if(A[i]==A[0]) a=i;
    if(t>a) ans=0;
    rep(i,n){
        if(i==0) D[0][0]=T[0],D[0][1]=1;
        else{ 
            D[i][0]=T[i];
            if(T[i]!=T[i-1]) D[i][1]=1;
            else D[i][1]=0;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(i==n-1){
            D[n-1][0]=A[n-1],D[n-1][1]=1;
        }
        else if(!D[i][1]){
            D[i][0]=min(T[i],A[i]);
            if(A[i]!=A[i+1]) D[i][1]=1;
        }
    }
    rep(i,n) if(!D[i][1]) ans=ans*(D[i][0])%mod;
    cout<<ans;
}