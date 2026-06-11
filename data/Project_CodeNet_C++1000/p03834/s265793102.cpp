#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  for (auto &c : s) c = (c == ',' ? ' ' : c);
  cout << s << '\n';

  return (0);
}
