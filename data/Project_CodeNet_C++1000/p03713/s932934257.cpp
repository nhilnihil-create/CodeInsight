#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define printVector(v) rep(i, v.size()) cout << v[i] << endl;

int main()
{
  int H, W;
  cin >> H >> W;
  long long ans = INT64_MAX;

  rep(cnt, 2)
  {
    FOR(i, 1, W - 1)
    {
      long long w1 = i;
      long long w2 = W - w1;
      long long h1 = H / 2;
      long long h2 = H - h1;
      long long S_max = max({w1 * H, w2 * h1, w2 * h2});
      long long S_min = min({w1 * H, w2 * h1, w2 * h2});
      ans = min(ans, S_max - S_min);
    }

    FOR(i, 1, W - 1)
    {
      long long w1 = i;
      long long w2 = (W - w1) / 2;
      long long w3 = W - w1 - w2;
      long long S_max = max({w1 * H, w2 * H, w3 * H});
      long long S_min = min({w1 * H, w2 * H, w3 * H});
      ans = min(ans, S_max - S_min);
    }

    swap(H, W);
  }
  cout << ans << endl;
  return 0;
}