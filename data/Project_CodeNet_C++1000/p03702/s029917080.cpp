#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, A, B;
vector<ll> H;

bool check(ll k) {
  ll x = 0;
  for (ll h : H) x += (max(h - B * k, 0ll) + (A - B) - 1) / (A - B);
  return x <= k;
}
int main() {
  cin >> N >> A >> B;
  H.resize(N);
  for (ll i = 0; i < N; ++i) cin >> H[i];
  ll ng = 0, ok = 1e9;
  while (ok - ng >= 2) {
    ll mid = (ok + ng) / 2;
    (check(mid) ? ok : ng) = mid;
  }
  cout << ok << endl;
  return 0;
}
