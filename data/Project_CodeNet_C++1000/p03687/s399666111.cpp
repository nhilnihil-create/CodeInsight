#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define SORT(v) sort(v.begin(), v.end());
#define RSORT(v) sort(v.rbegin(), v.rend());
#define REVERSE(v) reverse(v.begin(), v.end());

int shrinking_count(char c, string S)
{
  int rst = 0;
  while (S != string(S.size(), c))
  {
    rst++;
    string temp;
    rep(i, S.size() - 1)
    {
      if (S[i] == c || S[i + 1] == c)
        temp += c;
      else
        temp += S[i];
    }
    S = temp;
  }

  return rst;
}

int main()
{
  string s;
  cin >> s;

  int ans = INT32_MAX;
  rep(i, 26)
  {
    char c = 'a' + i;
    ans = min(ans, shrinking_count(c, s));
  }
  cout << ans << endl;
  return 0;
}