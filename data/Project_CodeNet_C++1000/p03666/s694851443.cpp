#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main() {
  ll N, A, B, C, D;
  cin >> N >> A >> B >> C >> D;
  N -= 1;
  ll dif = abs(A - B);
  vector<vector<ll>> pos;
  bool ok = false;
  for (ll i = 0; i <= N; ++i) {
    // cout << -D * i + C * (N - i) << ' ' << D * (N - i) - C * i << "\n";
    if ((-D * i + C * (N - i) <= dif) && (dif <= D * (N - i) - C * i)) {
      ok = true;
    }
  }
  if (ok) {
    cout << "YES" << "\n";
  }
  else {
    cout << "NO" << "\n";
  }
}
