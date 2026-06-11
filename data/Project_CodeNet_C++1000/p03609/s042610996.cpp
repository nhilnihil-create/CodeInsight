#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  int x, t;
  cin >> x >> t;
  int ans = max(0, x-t);
  cout << ans << endl;
  return 0;
}
