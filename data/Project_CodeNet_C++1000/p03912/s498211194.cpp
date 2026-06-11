#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// 解説写経
int main(){
  int N,M; cin >> N >> M;
  vector<ll> X(N); ll cnt[100010] = {};
  for(int i = 0; i < N; i++){ cin >> X[i]; cnt[X[i]]++;}
  
  vector<ll> Mod(M,0);
  vector<ll> Pr(M,0);
  
  for(int i = 0; i < 100010; i++){
    Mod[i%M] += cnt[i]; 
    Pr[i%M] += (cnt[i]/2)*2;
  }
  
  ll ans = 0;
  
  ans += Mod[0]/2;
  
  for(ll i = 1; i < (M+1)/2; i++){
    ll c = min(Mod[i],Mod[M-i]);
    ans += c;
    Mod[i] -= c;
    Mod[M-i] -= c;
  }
  
  if( M%2 == 0 ){ 
    ans += Mod[M/2]/2;
    Mod[M/2] = 0;
    
  }

  for(ll i = 1; i < M; i++){
    ans += min(Mod[i],Pr[i])/2;
  }
  
  cout << ans << endl;
  
  return 0;
}
  