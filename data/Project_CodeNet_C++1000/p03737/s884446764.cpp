#include <bits/stdc++.h>
using namespace std;
int main()
{
  string s, t, u;
  cin >> s >> t >> u;

  s = s[0] + ('A' - 'a');
  t = t[0] + ('A' - 'a');
  u = u[0] + ('A' - 'a');

  cout << s << t << u << endl;

  return 0;
}
