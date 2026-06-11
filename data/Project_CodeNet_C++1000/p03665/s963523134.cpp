#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll combo(ll a, ll b){
  if(b==0) return 1;
  else{
  ll ue=1;
  ll shita=1;
  for(ll i=a; i>=a-b+1; i--) ue*=i;
  for(ll i=1; i<=b; i++) shita*=i;
  return ue/shita;
  }
}

int main(){
  ll N, P; cin>>N>>P;
  vector<ll> B(N);
  ll odd=0;
  ll even=0;
  for(ll i=0; i<N; i++){
    ll A; cin>>A;
    if(A%2==0) even++;
    if(A%2==1) odd++;
  }
  ll ans;
  if(odd==0 && P==0) ans=pow(2, N);
  else if(odd==0 && P==1) ans=0;
  else ans=pow(2, N-1);
  cout<<ans<<endl;
}
