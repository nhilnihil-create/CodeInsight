#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void chmax(ll &a, ll b){ 
  if( a < b ){ swap(a,b);}
  
  return ;
} 

int main(){
  
  ll ans = 0;
  
  ll N,K; cin >> N >> K;
  vector<ll> A(N),B(N);
  for(ll i = 0; i < N; i++){ cin >> A[i] >> B[i];}
  
  for(ll i = 0; i < N; i++){ 
    if( (K | A[i]) == K ){ ans += B[i];}
  }
  
  ll mask = 0;
  
  for(ll i = 0; i <= 30; i++){ 
    // 1が出現する桁を探す
    
    if( (K >> i) & 1 ){ 
      ll pos = (K >> (i+1) ) << (i+1);
      
      ll now = mask|pos;
      
      ll sum = 0;
      
      for(ll j = 0; j < N; j++){ 
        if( (now | A[j]) == now ){ sum += B[j];}
      }
      
      ans = max(ans, sum);
  }
    
    mask |= (1<<i);
    
  }
  
  cout << ans << endl;
  
}