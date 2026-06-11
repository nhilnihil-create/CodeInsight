#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N; cin >> N;
  ll MAX;
  for (ll i = 0; i <= N; i++) {
    if (i * (i + 1) / 2 == N) MAX = i;
    else if (i * (i + 1) / 2 < N) MAX = i + 1;
    else break;
  }
  for (ll i = MAX; i >= 1; i--) {
    if (N >= i) {
      cout << i << '\n';
      N -= i;
    }
  }
  return 0;
}