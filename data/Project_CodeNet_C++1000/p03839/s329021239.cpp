#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n, k;
  cin >> n >> k;
  vector < int > a (n + 1);
  vector < ll > p (n + 2), lt (n + 2), rt (n + 2);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    p[i] = p[i - 1] + a[i];
  }

  for (int i = 1; i <= n; i++) {
    lt[i] = lt[i - 1] + (a[i] > 0 ? a[i] : 0);
  }
  for (int i = n; i >= 1; i--) {
    rt[i] = rt[i + 1] + (a[i] > 0 ? a[i] : 0);
  }

  ll ans = LLONG_MIN;
  for (int i = 1; i <= n - k + 1; i++) {
    ans = max ({ans, lt[i - 1] + rt[i + k] + (p[i + k - 1] - p[i - 1] > 0 ? p[i + k - 1] - p[i - 1] : 0)});
  }

  cout << ans << '\n';
}
