#include <bits/stdc++.h>
using namespace std;
const long mod = 1000000007;
int n;
int x[200000];
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> x[i];
  
  long ans = 1;
  int pos = 0;
  int cnt = 0;
  for (int z = 0; z < n; ++z) {
    while (pos < n - 1 && x[pos] > 2 * cnt) {
      ++pos;
      ++cnt;
    }
    ans = ans * (cnt + 1) % mod;
    --cnt;
  }
  cout << ans << endl;
}