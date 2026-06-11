#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define SORT(v) sort(v.begin(), v.end());
#define RSORT(v) sort(v.rbegin(), v.rend());
#define REVERSE(v) reverse(v.begin(), v.end());

int main()
{
  long long N;
  cin >> N;
  vector<long long> A(N);
  rep(i, N)
  {
    cin >> A[i];
  }
  A.push_back(0);

  long long card = 0;
  long long ans = 0;
  rep(i, N + 1)
  {
    card += A[i];
    if (A[i] == 0)
    {
      ans += card / 2;
      card = 0;
    }
  }
  cout << ans << endl;
  return 0;
}