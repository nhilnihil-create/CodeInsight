#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin>>n>>k;
  
  vector<ll> A(n);
  rep(i,n) cin>>A[i];
  
  ll mans=100100100100;
  for(int bit=0;bit<(1<<(n-1));bit++){
    ll ans=0;
    int cnt=0;
    rep(i,n-1){
      if(bit&(1<<i)) cnt++;
    }
    if(cnt!=k-1) continue;
    
    ll mh=A[0];
    for(int i=0;i<n-1;i++){
      if(bit&(1<<i)){
        if(A[i+1]<=mh){
          ans+=mh+1-A[i+1];
          mh=mh+1;
        }
      }
      mh=max(mh,A[i+1]);
    }
    mans=min(mans,ans);
  }
  
  cout<<mans<<endl;
  
  return 0;
}