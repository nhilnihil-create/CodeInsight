#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int s[] = { 14, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
  int a, b;
  cin >> a >> b;

  if (s[a-1] > s[b-1]) cout << "Alice\n";
  else if (s[a-1] < s[b-1]) cout << "Bob\n";
  else cout << "Draw\n";

  return (0);
}
