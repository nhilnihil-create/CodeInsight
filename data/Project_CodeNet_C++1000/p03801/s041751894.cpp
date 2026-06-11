#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//editorial AC
// The theme is understandable but installation is much more difficult than my ability
int main(){
  ll n; cin >> n;
  vector<ll> a(n);
  for(ll i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<ll> vec;
  
  ll res = -1;
  for(ll i = 0; i < n; i++){ 
    if( res < a[i] ){ res = a[i]; vec.push_back(i);}
  }
  
  
  map<ll,ll> mp;
  
  for(ll i = 0; i < n; i++){
    mp[a[i]]++;
  }
  
  vector<ll> ans(n,0LL);

  for(ll i = (ll)vec.size()-1; i >= 1; i--){ //index == 0 は別途調べる
    // index-vec[i] is the largest element in the current array A
    
    while( mp.rbegin()->first > a[vec[i-1]] ){
      
       auto v = *mp.rbegin();
       ans[vec[i]] += (v.first-a[vec[i-1]])*v.second;
       mp[a[vec[i-1]]] += v.second;
         
       mp.erase(v.first);
         
          }
  }
  
  for(auto v : mp ){
    ans[0] += v.first*v.second;
  }

  for(auto ne : ans ){ cout << ne << endl;}
  
 
  return 0;
}
          
          
          
          
    
        

    
    
    
  