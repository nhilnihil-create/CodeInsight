#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N; cin >> N;
  ll M; cin >> M;
  vector<ll> cnt(N, 0);
  for (ll i = 0; i < M; i++) {
    ll a, b; cin >> a >> b; a--; b--;
    cnt[a]++;
    cnt[b]++;
  }

  string ans = "YES";
  for (ll i = 0; i < N; i++) {
    if (cnt[i] % 2) ans = "NO";
  }
  cout << ans << '\n';
  return 0;
}