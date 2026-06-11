#include <bits/stdc++.h>

using namespace std;

#define range(i, m, n) for(int i = m; i < n; i++)
#define husk(i, m, n) for(int i = m; i > n; i--)

int n;
long long a, b, c, d;

int main() {
  cin >> n >> a >> b >> c >> d;
  long long sz = n - 1;
  // x + y == sz;
  // a + x * c - y * d <= b <= a + x * d - y * c
  // x * c - y * d <= b - a <= x * d - y * c
  range(x, 0, sz + 1) {
    int y = sz - x;
    if(a + c * x - d * y <= b && b <= a + d * x - c * y) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
