#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1000000007;

ll modpow(ll a, ll p){
  ll ret = 1;
  while(p){
    if(p & 1) ret = ret * a % mod;
    a = a * a % mod;
    p >>= 1;
  }
  return ret;
}

int main(){
  int n; cin >> n;
  vector<ll> a(n), num(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
    num[a[i]]++;
  }
  bool ok = true;
  if(n%2){
    if(num[0] != 1) ok = false;
    for(int i = 2; i < n; i += 2){
      if(num[i] != 2) ok = false;
    }
  }
  else{
    for(int i = 1; i < n; i += 2){
      if(num[i] != 2) ok = false;
    }
  }
  if(ok) cout << modpow(2, n/2) << endl;
  else cout << 0 << endl;
}