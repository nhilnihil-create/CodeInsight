#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

int main(){
  
  ll W,H; cin >> W >> H;
  
  priority_queue<P,vector<P> ,greater<P>> Q;
  
  for(ll i = 0; i < W; i++){
    ll p; cin >> p;
    
    Q.push({p,0});
    
  } 
  
  for(ll j = 0; j < H; j++){
    ll q; cin >> q;
    
    Q.push({q,1});
    
  }
  
  
  // 0 means coluumm while 1 means another direction
  
  ll ans = 0;
  
  ll cnt = 0;
  
  ll a = W+1,b = H+1;
  
  while( cnt <= (W+1)*(H+1)-1 && !Q.empty()){ 
    
    P p = Q.top(); Q.pop();
    
    if( p.second == 1){ ans += p.first*a; cnt += a;  b--;}
    else{ ans += p.first*b; cnt += b; a--;}
    
  }
  
  cout << ans << endl; 
  
  return 0;
}