#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  long long cnt1 = 0, sum = 0;
  for (int i = 0; i < n; ++i) {
    long long _sum = sum + a[i], su = (i & 1 ? _sum : -_sum);
    if (su >= 0) {
      cnt1 += su + 1;
      sum = (i & 1 ? -1 : 1);
    } else sum = _sum;
  }

  long long cnt2 = 0;
  sum = 0;
  for (int i = 0; i < n; ++i) {
    long long _sum = sum + a[i], su = (i & 1 ? -_sum : _sum);
    if (su >= 0) {
      cnt2 += su + 1;
      sum = (i & 1 ? 1 : -1);
    } else sum = _sum;
  }

  cout << min(cnt1, cnt2) << endl;
}
