#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vll = vector<ll> ;
using vs = vector<string> ;
#define all(v) v.begin(),v.end()
const ll mod = 1e9+7;

ll factori(ll i){
  ll tmp = 1;
  while(i>1){
    tmp*=i;
    i--;
    tmp%=mod;
  }
  return tmp;
}


int main(){
  ll N;cin>>N;
  vll A(N),B(100010,0),C(100010,0);rep(i,N)cin>>A[i];
  rep(i,N){
    if(i<=(N-1)/2) B[N-2*i-1]++;
    else B[2*i-N+1]++;
  }
  rep(i,N) C[A[i]]++;
  bool flag=true;
  ll ans=1;
  rep(i,100010){
    if(B[i]!=C[i]) flag=false;
    else if(B[i]>1){
      ans *= factori(B[i]);
      ans %= mod;
    }
  }
  if(flag) cout << ans << endl;
  else cout << 0 << endl;
}