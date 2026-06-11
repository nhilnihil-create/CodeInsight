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
  string A;
  cin >> A;
  long long ans = 1;
  vector<long long> count(30);
  rep(i, A.size())
  {
    ans += (i - count[A[i] - 'a']);
    count[A[i] - 'a']++;
  }
  cout << ans << endl;
  return 0;
}