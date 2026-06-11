#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int k, s;
  cin >> k >> s;
  int ans = 0;
  for (int x = 0; x <= k; x++) {
    for (int y = 0; y <= k; y++) {
      int z = s - x - y;
      if (z >= 0 && z <= k) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}