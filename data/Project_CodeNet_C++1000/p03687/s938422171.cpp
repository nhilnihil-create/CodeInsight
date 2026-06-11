/**
*    author:  yuya1234
*    created: 10.07.2020 13:31:12
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define REPD(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
#define FORD(i, a, b) for (ll i = a; i >= (ll)(b); i--)
#define FORV(i, v) for (auto i = v.begin(); i != v.end(); i++)

#define SORT(s) sort((s).begin(), (s).end())
#define SORTD(s) sort((s).rbegin(), (s).rend())
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());

#define SZ(x) ((int)(x).size())
#define MEMSET(v, h) memset((v), h, sizeof(v))

int main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  string s;
  cin >> s;

  int ans = INT_MAX - 1, cnt = 0;
  string ss;
  REP(i, 26)
  {
    cnt = 0;
    ss = s;
    for (;;)
    {
      bool flg = true;
      REP(j, SZ(ss) - 1)
      {
        if (ss[j] != ss[j + 1])
          flg = false;
      }
      if (flg)
      {
        ans = min(ans, cnt);
        break;
      }
      else
      {
        string ss1;
        int cnt1;
        cnt1 = 0;
        ss1 = "";
        FOR(j, 0, SZ(ss) - 2)
        {
          if ((ss[j] - 'a') == i || (ss[j + 1] - 'a') == i)
          {
            ss1 += char(i+'a');
            cnt1++;
          }
          else
            ss1 += ss[j];
        }
        if (cnt1 == 0)break;
        ss = ss1;
        cnt++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}