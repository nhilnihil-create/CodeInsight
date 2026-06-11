#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

ll mod(ll a, ll b){
  ll ret=a%b;
  if(ret<0) ret+=b;
  return ret;
}

ll modpow(ll a,ll b,ll c){
  ll res=1;
  while(b>0){
    if(b&1) res=mod(res*a,c);
    a=mod(a*a,c);
    b>>=1;
  }
  return res;
}

int main() {
  int n,x;
  cin>>n>>x;
  int a[n];
  for(int i=0;i<n;i++) cin>>a[i];
  ll ans=0;
  for(int i=0;i<n-1;i++){
    if(a[i]+a[i+1]<=x)continue;
    else{
      if(a[i]<=x){
        ans+=(a[i+1]+a[i])-x;
        a[i+1]-=(a[i+1]+a[i])-x;
      }
      else{
        ans+=(a[i+1]+a[i])-x;
        a[i+1]=0;
        a[i]-=(x-a[i+1]);
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}