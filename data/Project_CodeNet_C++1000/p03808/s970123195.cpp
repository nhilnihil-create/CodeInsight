#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define rep(i, j, n) for (int i = (j); i < (n); ++i)
#define rrep(i, j, n) for (int i = (n)-1; i >= (j); --i)
using namespace std;
using ll = long long;
constexpr int INF = 1 << 30;

int main()
{
  ll n;
  cin >> n;
  vector<ll> a(n);

  ll s = 0;
  rep(i, 0, n)
  {
    cin >> a[i];
    s += a[i];
  }

  if (s % (n * (n + 1) / 2))
  {
    cout << "NO" << endl;
    return 0;
  }
  ll op_cnt = s / (n * (n + 1) / 2);

  bool ok = true;
  ll cnt = 0;
  rep(i, 0, n)
  {
    ll d = a[(i + 1) % n] - a[i];
    // d == x - (op_cnt - x) * (n - 1)
    // d == x + x * (n - 1) - op_cnt * (n - 1)
    // (d + op_cnt * (n - 1)) / n == x
    ll e = d + op_cnt * (n - 1);
    if (e % n == 0 && 0 <= e / n && e / n <= op_cnt)
      cnt += op_cnt - e / n;
    else
      ok = false;
  }
  ok &= cnt == op_cnt;

  cout << (ok ? "YES" : "NO") << endl;
  return 0;
}
