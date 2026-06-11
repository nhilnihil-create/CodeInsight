#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  bool works = false;
  --n;
  for (int i = 0; i <= n; ++i) {
    long long lo = a - d * i + (n - i) * c;
    long long hi = a - c * i + (n - i) * d;
    if (lo <= b && b <= hi) {
      works = true;
      break;
    }
  }
  cout << (works ? "YES" : "NO") << endl;
  return 0;
}
