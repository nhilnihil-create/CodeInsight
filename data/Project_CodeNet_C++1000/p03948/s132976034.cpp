#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
int main(){
    int n,t,A[200000],B[200000],ans=1;
    cin>>n>>t;
    rep(i,n) cin>>A[i];
    B[n-1]=A[n-1];
    for(int i=n-2;i>=0;i--) B[i]=max(B[i+1],A[i]);
    rep(i,n) B[i]-=A[i];
    sort(B,B+n,greater<int>());
    rep(i,n-1) if(B[i+1]==B[0]) ans++;
    cout<<ans;
}