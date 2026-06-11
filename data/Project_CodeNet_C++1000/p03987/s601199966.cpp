#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
int main(){
    ll n,A[200000],B[200000]={0},ans=0;
  
    cin>>n;
  
    rep(i,n)
      cin>>A[i],B[A[i]]=i+1;
  
    set<ll> C;
  
    C.insert(0),C.insert(n+1);
  
    rep(i,n) ans+=(i+1)*(B[i+1]-(*--C.lower_bound(B[i+1])))*(*C.upper_bound(B[i+1])-B[i+1]),C.insert(B[i+1]);
    cout<<ans;
}
