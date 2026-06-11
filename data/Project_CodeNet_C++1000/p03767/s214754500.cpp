#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<ll> a(3 * N);
  REP(i, 3 * N) { cin >> a.at(i); }
  sort(a.begin(), a.end(), greater<ll>());
  ll ans = 0ll;
  for (int i = 1; i < 2 * N; i += 2) {
    ans += a.at(i);
  }
  cout << ans << endl;

  return 0;
}
