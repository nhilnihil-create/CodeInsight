#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

ll comb_count(int n, int m) {
  if (m == 0)
    return 1;
  if (n == 0)
    return 0;
  return (n * comb_count(n - 1, m - 1) / m);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, p;
  cin >> n >> p;
  vector<int> a(n);
  int eve = 0, odd = 0;
  rep(i, 0, n) {
    cin >> a[i];
    if (a[i] & 1)
      odd++;
    else
      eve++;
  }

  ll eves = pow(2, eve);
  ll odds = 0;
  int start = 1;
  if (p == 0)
    start = 0;
  for (int i = start; i <= odd; i += 2) {
    odds += comb_count(odd, i);
  }

  cout << eves * odds << endl;
}
