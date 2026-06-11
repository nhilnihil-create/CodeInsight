#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  ll n;
  cin >> n;
  map<ll,ll> rec;
  vector<ll> c(n);
  vector<ll> v(0);
    
  for(long long i = 0; i < n; i++){
    cin >> c[i];
  }
  
 for(long long i = 0; i < n; i++){
    if(rec.count(c[i])){
      rec.at(c[i]) = rec.at(c[i]) + 1;
      if(rec.at(c[i]) == 2){
        v.push_back(c[i]);
      }
      if(rec.at(c[i]) == 4){
        v.push_back(c[i]);
      }
    }
    else{
      rec[c[i]] = 1;
    }
  }
 
  if(v.size() == 0 || v.size() == 1){
    cout << 0;
    return 0;
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
    cout << v[0] * v[1];
    
    
    
  return 0;
}