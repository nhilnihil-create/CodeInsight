#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool contain(ll a, ll b) {
  for (int i = 0; i < 30; i++) {
    if (!(a >> i & 1)) continue;
    if (!(b >> i & 1)) return false;
  }
  return true;
}

int main(void) {
  ll N, K;
  cin >> N >> K;

  vector<ll> a(N), b(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i] >> b[i];
  }

  vector<ll> v(1, K);
  for (int i = 0; i < 30; i++) {
    if (!(K >> i & 1)) continue;
    v.push_back(((K >> (i + 1)) << (i + 1)) + (1 << i) - 1);
  }

  ll ans = 0;
  for (int i = 0; i < v.size(); i++) {
    ll sum = 0;
    for (int j = 0; j < N; j++) {
      if (!contain(a[j], v[i])) continue;
      sum += b[j];
    }
    ans = max(ans, sum);
  }
  cout << ans << endl;

  return 0;
}