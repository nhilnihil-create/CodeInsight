#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll q, h, s, d, n;
  cin >> q >> h >> s >> d >> n;

  ll sumq = n * 4 * q;
  ll sumh = n * 2 * h;
  ll sums = n * s;
  ll sumd = n / 2 * d;

  if (n & 1)
    sumd += min({4 * q, 2 * h, s});
  cout << min({sumq, sumh, sums, sumd}) << endl;
}
