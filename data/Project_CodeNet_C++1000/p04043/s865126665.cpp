#include <bits/stdc++.h>

using namespace std;

int main (void)
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int a, b, c;
  cin >> a >> b >> c;
  if ((a == 5 && b == 5 && c == 7) || (a == 5 && b == 7 && c == 5) || (a == 7 && b == 5 && c == 5)) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }
  return 0;
}
// created: 20.07.2020 16:50:01 IST
