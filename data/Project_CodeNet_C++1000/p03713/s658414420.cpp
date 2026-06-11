#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
#define fi first
#define se second
#define pb push_back
#define wzh(x) cerr<<#x<<'='<<x<<endl;
int n,m;
int main() {
  ios::sync_with_stdio(false);
  cin>>n>>m;
  if(n%3==0 || m%3==0)cout<<0<<'\n';
  else{
    LL ans=LLONG_MAX;
    for(int i=1;i<n;i++){
      LL now=1ll*i*m;
      LL l=1ll*(n-i)*(m/2);
      LL r=1ll*(n-i)*((m+1)/2);
      ans=min(ans,max({l,r,now})-min({l,r,now}));
    }
    for(int i=1;i<m;i++){
      LL now=1ll*i*n;
      LL l=1ll*(m-i)*(n/2);
      LL r=1ll*(m-i)*((n+1)/2);
      ans=min(ans,max({l,r,now})-min({l,r,now}));
    }
    if(n>=3){
      ans=min(ans,1ll*m);
    }
    if(m>=3){
      ans=min(ans,1ll*n);
    }
    cout<<ans<<'\n';
  }
  return 0;
}