#include <bits/stdc++.h>
#define rep(i, ns, ne) for (int i = ns; i < ne; ++i)
using namespace std;

int main() {
  int a, b, c, d, ans = 0;
  cin >> a >> b >> c >> d;
  ans = max(a * b, c * d);
  cout << ans << endl;
  getchar();
}