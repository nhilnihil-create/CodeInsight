#include <bits/stdc++.h>
using namespace std;

int main() {
  long S, C;
  cin >> S >> C;
  long s = S;
  long c = C / 2;
  long tmp = min(s, c);
  long ans = 0;
  ans += tmp;
  S -= tmp;
  C -= tmp * 2;
  if (C <= 1) return cout << ans << "\n", 0;
  ans += C / 4;
  cout << ans << "\n";
}