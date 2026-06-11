#include <bits/stdc++.h>
#define rep(i,a,n) for(int i =a; i<n; i++)
#define ll long long
using namespace std;

int main() {
  int N; ll K; cin >> N >> K;
  map<ll,ll> map;
  
  rep(i,0,N) {
    ll a,b; cin >> a >> b;
    if (map[a] ==0) map[a] = b;
    else map[a] += b;
  }
  
  ll tmp =0, ans;
  for (auto x: map) {
    tmp += x.second;
    if (tmp >= K) {
      ans = x.first; break;
    }
  }
  cout << ans << endl;
}