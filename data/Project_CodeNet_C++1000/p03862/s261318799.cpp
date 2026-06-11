#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, max;
  cin >> n >> max;
  vector<int> num(n);
  for (int i = 0; i < n; i++) {
    cin >> num[i];
  }
  long long ans = 0;
  if (num[0] > max) {
    ans += (num[0] - max);
    num[0] = max;
  }
  for (int i = 1; i < n - 2; i++) {
    if (num[i] + num[i - 1] > max) {
      ans += (num[i] + num[i - 1] - max);
      num[i] = max - num[i - 1];
    }
  }
  if (num[n - 1] + num[n - 2] > max) {
    ans += (num[n - 1] + num[n - 2] - max);
  }
  cout << ans << endl;
}
