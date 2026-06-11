#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define printVector(v) rep(i, v.size()) cout << v[i] << endl;

int main()
{
  long long N, A, B, preX;
  cin >> N >> A >> B >> preX;
  long long ans = 0;

  rep(i, N - 1)
  {
    long long X;
    cin >> X;
    ans += min((X - preX) * A, B);
    preX = X;
  }
  cout << ans << endl;
  return 0;
}