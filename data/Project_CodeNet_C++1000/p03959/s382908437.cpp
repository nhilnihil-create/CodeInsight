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
  int MOD=1000000007;
  int n;
  cin>>n;
  int t[n],a[n],check[n],pos_t[n],pos_a[n];
  for(int i=0;i<n;i++){
    cin>>t[i];
    check[i]=0;
  }
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  check[0]=1;
  pos_t[0]=t[0];
  for(int i=1;i<n;i++){
    if(t[i-1]<t[i]){
      check[i]=1;
    }
    pos_t[i]=t[i];
  }
  check[n-1]+=2;
  pos_a[n-1]=a[n-1];
  for(int i=n-2;i>=0;i--){
    if(a[i+1]<a[i]){
      check[i]+=2;
    }
    pos_a[i]=a[i];
  }
  ll ans=1;
  for(int i=0;i<n;i++){
    if(check[i]==0){
      ans=mod(ans*min(pos_a[i],pos_t[i]),MOD);
    }
    else if(check[i]==1){
      if(pos_t[i]<=pos_a[i])continue;
      else ans=0;
    }
    else if(check[i]==2){
      if(pos_a[i]<=pos_t[i])continue;
      else ans=0;
    }
    else{
      if(pos_a[i]==pos_t[i])continue;
      else ans=0;
    }
  }
  cout<<ans<<endl;
  return 0;
}