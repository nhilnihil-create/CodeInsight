#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using vin=vector<int>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;

ll kaijo(ll x){
  if(x==1) return x=1; 
  return x%inf*kaijo(x-1)%inf;
}



int main() {
  ll n,k;
  cin>>n>>k;
  vin a(n),b(n);
  rep(i,n) cin>>a[i]>>b[i];
  /////
  map<ll,ll> mp;
  rep(i,n){
    mp[a[i]]+=b[i]; 
  }
  ll count=0;
  for(auto v:mp){
    count+=v.second;
    if(count>=k) {
      cout<<v.first<<endl;
      return 0;
    }
  }
  
  
  
  
}