#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define rep(i,n) for(int i=0;i<n;i++)
const ll MOD=1000000000000000000;
const long double PI=3.14159265358979;
const ll MAX=100;

ll fac[MAX];
ll faci[MAX];

ll modpow(ll x,ll y){
  long long ans=1;
  while(y>0){
    if(y&1){
      ans*=x%MOD;
    }
    x*=x%MOD;
    x%=MOD;
    ans%=MOD;
    y>>=1;
  }
  return ans;
}

void modCf(){
  fac[0]=1;
  faci[0]=1;
  for(int i=1;i<MAX;i++){
    fac[i]=fac[i-1]*i%MOD;
    faci[i]=modpow(fac[i],MOD-2);
  }
  return;
}

ll modC( ll x,ll y){
  ll ans=1;
  for(int i=0;i<y;i++){
    ans*=(x-i);
    ans/=(i+1);
  }
  return ans;
}


int main() {
  modCf();
  ll N,P;
  cin>>N>>P;
  ll all=modpow(2,N),cnt=0;
  //cout<<all<<endl;
  rep(i,N){
    ll a;
    cin>>a;
    if(a%2){
      cnt++;
    }
  }
  ll ans=0,c=N-cnt;
  c=modpow(2,c);
  //cout<<c;
  for(int i=1;i<=cnt;i+=2){
    ans+=modC(cnt,i)*c;
    //cout<<fac[3]<<endl;
  }
  if(P==1){
    cout<<ans;
  }
  else{
    cout<<all-ans;
  }
}

