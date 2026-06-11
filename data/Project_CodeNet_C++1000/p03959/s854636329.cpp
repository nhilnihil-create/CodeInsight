#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  ll n;
  cin >> n;
  vector<ll> t(n),a(n);
  rep(i,n)cin >> t[i];
  rep(i,n)cin >> a[i];
  vector<ll> v(n,-1);
  rep(i,n)if(i == 0 || t[i] != t[i-1])v[i] = t[i];
  ll res = 1;
  for(ll i = n-1;i >= 0;i--){
    if(i == n-1 || a[i] != a[i+1]){
      if(v[i] != -1 && v[i] != a[i])res = 0;
      v[i] = a[i];
    }
  }
  rep(i,n)if(v[i] > a[i] || v[i] > t[i])res = 0;
  rep(i,n){
    if(v[i] != -1)continue;
    (res *= min(a[i],t[i]))%= MOD;
  }
  cout << res << endl;

  


  
  


  return 0;
}