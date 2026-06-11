#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, ans = 1000000000;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }
  for (int i = -100; i <= 100; i++) {
    int s = 0;
    for (int j = 0; j < n; j++) {
      s += (a.at(j) - i) * (a.at(j) - i);
    }
    ans = min(ans, s);
  }
  cout << ans << endl;
}
