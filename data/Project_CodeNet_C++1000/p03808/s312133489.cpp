#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  long long sum = accumulate(a.begin(), a.end(), 0ll);
  long long psum = (long long) n * (n + 1) / 2;
  if (sum % psum) {
    cout << "NO" << endl;
    return 0;
  }
  long long m = sum / psum;
  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    int d = a[i] - a[(i + n - 1) % n];
    if ((m - d) % n || m - d < 0) {
      cout << "NO" << endl;
      return 0;
    }
    c[i] = (m - d) / n;
  }
  long long cnt = accumulate(c.begin(), c.end(), 0ll);
  if (cnt != m) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
  return 0;
}
