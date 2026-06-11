#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define printVector(v) rep(i, v.size()) cout << v[i] << endl;

int main()
{
  int A, B;
  cin >> A >> B;
  int ans = A + B;
  if (ans >= 10)
  {
    cout << "error" << endl;
    return 0;
  }
  cout << ans << endl;
  return 0;
}