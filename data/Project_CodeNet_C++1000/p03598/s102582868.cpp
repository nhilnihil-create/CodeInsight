#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, k;
  cin >> n >> k;
  vector<int> vx(n);
  for (int i = 0; i < n; ++i) {
    cin >> vx[i];
  }
  
  int ans = 0;
  for (int i = 0; i < vx.size(); ++i) {
    ans += min(vx[i], abs(vx[i] - k)) * 2;
  }

  cout << ans << '\n';
}
