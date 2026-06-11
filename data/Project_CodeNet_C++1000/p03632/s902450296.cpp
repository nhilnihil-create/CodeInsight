#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int left = max(a, c);
  int right = min(b, d);
  int res = max(right - left, 0);
  cout << res << endl;
}
