#include <bits/stdc++.h>

using namespace std;

string p, q;
int s1[100002], s2[100002], t, a, b, c, d;

int main()
{
  cin >> p >> q >> t;
  int n = p.size();
  int m = q.size();
  p = '#' + p;
  q = '#' + q;
  for (int i = 1; i <= n; i++)
    if (p[i] == 'A')
      s1[i] = s1[i - 1] + 1;
    else
      s1[i] = s1[i - 1] + 2;
  for (int i = 1; i <= m; i++)
    if (q[i] == 'A')
      s2[i] = s2[i - 1] + 1;
    else
      s2[i] = s2[i - 1] + 2;
  while (t--) {
    cin >> a >> b >> c >> d;
    int r1 = (s1[b] - s1[a - 1]) % 3;
    int r2 = (s2[d] - s2[c - 1]) % 3;
    if (r1 != r2)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}
