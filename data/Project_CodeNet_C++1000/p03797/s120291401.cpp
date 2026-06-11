#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll n, m;cin>>n>>m;
  ll ans=min(n, m/2);
  m = max(0LL, m - n*2);
  ans += m / 4;
  cout << ans;
}
