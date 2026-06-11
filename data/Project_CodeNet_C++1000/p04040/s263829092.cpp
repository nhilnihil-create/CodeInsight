#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD=1000000007;

//mod冪乗
ll mp(ll a,ll b) {
  ll ans = 1;
  while (b) {
  if (b % 2)
    ans *= a;
    a *= a;
    a %= MOD;
    ans %= MOD;
    b /= 2;
  }
  return ans;
}

//mod割り算
ll moddiv(ll a,ll b) {
  a %= MOD;
  return (a*mp(b, MOD - 2)) % MOD;
}

int main(){
  ll H,W,A,B,ans=0,cnta=1,cntb=1;
  cin>>H>>W>>A>>B;
  vector<ll> XB(H,1);
  vector<ll> XW(H,1);
  for(int i=1;i<H;i++){
    cnta*=moddiv(B+i-1,i);
    cnta%=MOD;
    cntb*=moddiv(W-B+i-1,i);
    cntb%=MOD;
    XB[i]=cnta;
    XW[H-1-i]=cntb;
    //cout<<cnta<<" "<<cntb<<endl;
  }
  for(int i=0;i<H-A;i++){
    ans+=XB[i]*XW[i];
    ans%=MOD;
  }
  cout<<ans<<endl;
}