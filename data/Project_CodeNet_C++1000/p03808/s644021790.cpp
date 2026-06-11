#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum % (1LL * n * (n + 1) / 2) != 0) {
    cout << "NO" << endl;
    return 0;
  }
  a[n] = a[0];
  long long k = sum / (1LL * n * (n + 1) / 2);
  vector<int> dif(n);
  for (int i = 0; i < n; i++) {
    dif[i] = a[i + 1] - a[i];
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (dif[i] == k) continue;
    else if (dif[i] > k) {
      cout << "NO" << endl;
      return 0;
    } else {
      long long tmp = k - dif[i];
      if (tmp % n != 0) {
        cout << "NO" << endl;
        return 0;
      } else {
        cnt += tmp / n;
      }
    }
  }
  cout << (cnt == k ? "YES" : "NO") << endl;
  return 0;	
}