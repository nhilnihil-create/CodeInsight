#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define printVector(v) rep(i, v.size()) cout << v[i] << endl;

int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  vector<int> count(N);
  rep(i, N)
  {
    cin >> A[i];
    count[A[i]]++;
  }
  bool is_ok = true;
  if (N % 2 == 0)
  {
    if (count[0] != 0)
      is_ok = false;
    for (int i = 1; i < N; i++)
    {
      if (i % 2 == 1 && count[i] != 2)
        is_ok = false;
      else if (i % 2 == 0 && count[i] != 0)
        is_ok = false;
    }
  }
  else
  {
    if (count[0] != 1)
      is_ok = false;

    for (int i = 1; i < N; i++)
    {
      if (i % 2 == 0 && count[i] != 2)
        is_ok = false;
      else if (i % 2 == 1 && count[i] != 0)
        is_ok = false;
    }
  }
  long long ans = 0;
  if (is_ok)
  {
    ans = 1;
    int mod = 1e9 + 7;
    rep(i, N / 2)
    {
      ans *= 2;
      ans %= mod;
    }
  }
  cout << ans << endl;
  return 0;
}