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
  ll pows = 0,sums = 0;
  rep(i,n){
    ll x;cin >> x;
    sums += x;
    pows += x*x;
  }
  ll d = sums/n;
  ll res = 1ll << 60;
  res = min(res,d*d*n-2*d*sums+pows);
  d++;
  res = min(res,d*d*n-2*d*sums+pows);
  cout << res << endl;






  

  return 0;
}