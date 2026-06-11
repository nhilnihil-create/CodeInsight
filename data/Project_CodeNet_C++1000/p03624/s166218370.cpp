#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define RREP(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define INF 1000000000000
typedef long long ll;

int main()
{
  int n, m;
  string s;
  vector<char> a(26);

  cin >> s;

  REP(i, ('z' - 'a') + 1)
  {
    a[i] = 'a' + i;
  }
  REP(i, s.size())
  {
    a[s[i] - 'a'] = '0';
  }
  REP(i, a.size())
  {
    if (a[i] != '0')
    {
      cout << a[i] << endl;
      break;
    }
    else if (i == a.size() - 1)
    {
      cout << "None" << endl;
    }
  }
}