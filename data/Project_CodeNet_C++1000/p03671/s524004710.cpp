#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a[3];
  rep(i, 3) cin >> a[i];
  sort(a, a + 3);
  int ans = a[0] + a[1];
  cout << ans << endl;
  return 0;
}