#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  int beg = max(a, c), en = min(b, d);
  int ans = en - beg;
  if(ans < 0) ans = 0;
  cout << ans;
}