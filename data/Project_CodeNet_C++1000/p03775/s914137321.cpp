#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int cnt_digits(ll n) {
  int cnt = 0;
  while (n > 0) {
    cnt++;
    n /= 10;
  }
  return cnt;
}

int main() {
  ll n;
  cin >> n;

  int ans = cnt_digits(n);
  for (ll a = 1; a * a <= n; a++) {
    if (n % a) continue;
    ll b = n / a;
    int cur = max(cnt_digits(a), cnt_digits(b));
    ans = min(ans, cur);
  }
  cout << ans << endl;
  return 0;
}
