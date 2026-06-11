#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
ll Mod = 1000000007;
int main() {
  ll N,K;
  cin >> N >> K;
  ll ans = -1;
  vector<P> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a.begin(),a.end());
  for (int i = 0; i < N; i++) {
    K -= a[i].second;
    if (K <= 0) {
      ans = a[i].first;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}