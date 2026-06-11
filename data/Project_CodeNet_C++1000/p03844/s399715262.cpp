#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a, b;
  char op;
  cin >> a >> op >> b;

  if (op == '+') cout << a + b << '\n';
  else cout << a - b << '\n';

  return (0);
}
