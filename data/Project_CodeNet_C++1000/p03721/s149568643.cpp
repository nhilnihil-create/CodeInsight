#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

int main() {
  ll n,k;
  cin >> n >> k;
  vector<pair<ll,ll>> ins(n);
  rep(i,n){
    ll a,b;
    cin >> a >> b;
    ins[i] = make_pair(a,b);
  }
  
  sort(ins.begin(),ins.end());
  
  ll cnt=0,i=0;
  while(cnt < k){
    cnt += ins[i].second;
    i++;
  }
  
  //cout << i << endl;
  cout << ins[i-1].first << endl;

  return(0);
}