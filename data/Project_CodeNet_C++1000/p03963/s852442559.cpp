#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

/*
int 2の32乗 -1        10の9乗
long long 2の63乗 -1  10の18乗
*/

int main() {
  int N, K;
  cin >> N >> K;
  ll ans = K;
  rep(i, 0, N - 1) ans *= K - 1;
  cout << ans << endl;
  return 0;
}
