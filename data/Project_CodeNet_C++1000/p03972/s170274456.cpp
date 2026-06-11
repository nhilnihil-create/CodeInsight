#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  ll W,H; cin >> W >> H;
  
  ll a = W+1; 
  ll b = H+1;
  
  vector<pair<ll,ll>> edge;
  
  for(int i = 0; i < W; i++){
    ll p; cin >> p; edge.push_back({p,1});
    // 1 は x方向を意味
  }
  
  for(int j = 0; j < H; j++){
    ll q; cin >> q; edge.push_back({q,2});
  }
  
  sort(edge.begin(),edge.end());
  
 
  int itr = 0; 
  
  ll ans = 0; ll cnt = 0;
  
  while( true ){
    
    ll cost = edge[itr].first;
    int dir = edge[itr].second;
    
    if( dir == 1 && a > 0){ 
      ans += cost*b; cnt += b; a--; 
    }
    if( dir == 2 && b > 0){
      ans += cost*a; cnt += a; b--;
    }
    
    if( cnt >= (W+1)*(H+1)-1){break;}
       
    itr++;
  }
  
  cout << ans << endl;
  
  return 0;
}
    
