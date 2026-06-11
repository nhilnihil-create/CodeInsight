#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;
ll temp_mod=pow(10,9)+7;

ll Kaijou(ll x) {
  ll ret_val=1;
  for (ll i=1;i<=x;i++) ret_val=((ret_val*i)%temp_mod);
  return ret_val;
}

int main() {
  ll N,M; cin >>N >>M;

  int temp=abs(N-M);

  if (0==temp) {
    int ans=((2*Kaijou(N)*Kaijou(M))%temp_mod);
    cout <<ans <<endl;
    return 0;
  }else if (1==temp) {
    int ans=((Kaijou(N)*Kaijou(M))%temp_mod);
    cout <<ans <<endl;
    return 0;
  } else {
    cout <<0 <<endl;
    return 0;
  }
}
