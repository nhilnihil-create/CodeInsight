#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define printVector(v) rep(i, v.size()) cout << v[i] << endl;

int main()
{
  int N, T;
  cin >> N >> T;
  int ans = 0;
  int pre_t = 0;
  cin >> pre_t;
  rep(i, N - 1)
  {
    int t;
    cin >> t;
    if (t - pre_t < T)
      ans += t - pre_t;
    else
      ans += T;
    pre_t = t;
  }
  ans += T;
  cout << ans << endl;
  return 0;
}