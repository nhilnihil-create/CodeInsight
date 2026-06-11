#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007


int main(){

  int n;
  cin >> n;
  vector<ll> v(n,0);
  rep(i,n){
    int x;cin >> x;
    v[x]++;
  }
  ll res = 1;
  bool is = true;
  if(n & 1){
    if(v[0] != 1)is = false;
    for(int i = 1;i < n;i++){
      if(i & 1){
        if(v[i] != 0)is = false;
      }else{
        if(v[i] != 2)is =false;
        else (res *= 2)%= MOD;
      }
    }
  }else{
    rep(i,n){
      if(i & 1){
        if(v[i] != 2)is = false;
        else (res *= 2)%= MOD;
      }else{
        if(v[i] != 0)is = false;
      }
    }
  }
  is ? cout << res << endl : cout << 0 << endl;
  




  return 0;
}