#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n,t;
  cin >> n >> t;
  vector<ll> time(n);
  rep(i,n) cin >> time[i];
  ll ans = 0;
  for (int i = 1; i < n; i++) {
    int tmp = time[i]-time[i-1];
    if (tmp <= t) {
      ans += tmp;
    } else {
      ans += t;
    }
  }
  ans += t;
  cout << ans << endl;
  return 0;
}