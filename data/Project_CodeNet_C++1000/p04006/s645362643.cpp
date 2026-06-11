#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
int main(){
    ll n,x,A[200001],B[2001][2001];
    ll ans=1e18;
    cin>>n>>x;
    rep(i,n) cin>>A[i],B[i][i]=A[i];
    rep(i,n)rep(j,n-1) B[i][(i+j+1)%n]=min(B[i][(i+j)%n],A[(i+j+1)%n]);
    rep(i,n){
        ll y=0;
        rep(j,n) y+=B[j][(j+i)%n];
        ans=min(ans,y+x*i);
    }
    cout<<ans;
}