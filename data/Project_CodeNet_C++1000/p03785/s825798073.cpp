#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int n, c, k;
  cin >> n >> c >> k;
  vector<int> t(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  sort(all(t));
  int ans = 0;
  int now_max = t[0] + k;
  int now_n = 0;
  for (int i = 0; i < n; i++) {
    if (t[i] <= now_max && now_n + 1 <= c) {
      now_n++;
    } else {
      ans++;
      now_max = t[i] + k;
      now_n = 1;
    }
  }
  if (now_n > 0) ans++;
  cout << ans << endl;
  return 0;
}