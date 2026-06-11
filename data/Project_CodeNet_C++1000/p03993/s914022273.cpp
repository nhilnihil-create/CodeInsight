#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0;i < (n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vl>;

ll gcd(ll a,ll b){
  if(b == 0) return a;
  return gcd(b , a % b);
}

ll mod(ll a){
  return a % 1000000007;
}


int main(){
  ll n; cin >> n; vl like(n); ll count = 0;
  rep(i,n){ ll x; cin >> x; like[i] = x-1; }
  
  for(ll i=0; i < n; i++){
    
    if(like[like[i]] == i) count++;
  
  }
  
  cout << count/2 << endl;
}