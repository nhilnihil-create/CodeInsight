#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define printVector(v) rep(i, v.size()) cout << v[i] << endl;

int main()
{
  long long N, M;
  cin >> N >> M;
  long long ans;
  if (N >= M)
  {
    ans = M / 2;
  }
  else
  {
    M = max((long long)0, M - (2 * N));
    ans = N + (M / 4);
  }
  cout << ans << endl;
  return 0;
}