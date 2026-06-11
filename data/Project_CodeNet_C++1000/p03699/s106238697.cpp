#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  int n;
  cin >> n;

  vector<int> s(n);
  for (int i = 0; i < n; i++) cin >> s[i];

  int sum = accumulate(s.begin(), s.end(), 0);
  if (sum % 10 != 0) {
    cout << sum << endl;
    return 0;
  }

  sort(s.begin(), s.end());
  int t = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] % 10 != 0) {
      t = s[i];
      break;
    }
  }
  int ans;
  if (t == 0)
    ans = 0;
  else
    ans = sum - t;

  cout << ans << endl;
}
