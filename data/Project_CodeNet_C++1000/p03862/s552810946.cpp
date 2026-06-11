
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }
  int first = a.at(0);
  long long ans = 0;
  for (int i = 1; i < n; i++) {
    int tmp = max(0, a.at(i) + a.at(i - 1) - x);
    ans += tmp;
    a.at(i) = max(0, a.at(i) - tmp);
  }
  cout << ans;
  return 0;
}