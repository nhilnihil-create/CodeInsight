#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define int ll
#define all(v) v.begin(), v.end()
#define reps(__i, a, b) for (int __i = a; i < b; i++)
#define rep(__i, n) reps(__i, 0, n)

const ll INF = (1ll << 60);
const ll MOD = (ll)1e9 + 7;

signed main()
{
  string s;
  int k;
  cin >> s >> k;

  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] != 'a' && 'z' - s[i] + 1 <= k)
    {
      k -= ('z' - s[i] + 1);
      s[i] = 'a';
      // cout << 'K' << k << endl;
    }
    // cout << ':' << s << endl;
  }
  if (k > 0)
  {
    k %= 26;
    s[s.length() - 1] = 'a' + (s[s.length() - 1] + k - 'a') % 26;
  }
  cout << s << endl;
}