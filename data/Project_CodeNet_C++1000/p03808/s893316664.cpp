#include <bits/stdc++.h>
using namespace std;

long long n, sum = 0;
vector<int> a;
bool res = 1;

int main() {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum % (n * (n + 1) / 2) != 0)
    res = 0;
  else {
    long long cnt = 0, k = sum / (n * (n + 1) / 2);
    for (int i = 0; i < n; ++i) {
      long long diff = a[(i + 1) % n] - a[i] - k;
      if (diff % n != 0 || diff > 0) res = 0;
      cnt += -diff / n;
    }
    if (cnt != k) res = 0;
  }
  if (res)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
