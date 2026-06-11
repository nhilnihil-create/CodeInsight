#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  long long t, a, x, y;
  cin >> x >> y;
  for (int i = 1; i < n; ++i) {
    cin >> t >> a;
    long long k = ((x+t-1)/t > (y+a-1)/a ? (x+t-1)/t : (y+a-1)/a);
    x = k*t;
    y = k*a;
  }
  cout << x + y << endl;

  return 0;
}

