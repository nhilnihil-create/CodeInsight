#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;
using ll = long long;

int main() {
  ll N, K;
  cin >> N >> K;

  map<ll, ll> mp;
  rep(i,0,N-1) {
    ll a, b;
    cin >> a >> b;
    mp[a] += b;
  }

  ll sum = 0;
  for (auto p : mp) {
    sum += p.second;
    if (K <= sum) {
      cout <<  p.first << endl;
      break;
    }
  }

  return 0;
}
