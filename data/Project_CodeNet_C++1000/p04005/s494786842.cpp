#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a[3];
  rep(i, 3) cin >> a[i];
  if (a[0] % 2 == 0 || a[1] % 2 == 0 || a[2] % 2 == 0) cout << 0 << endl;
  else {
    sort(a, a + 3);
    cout << (ll)a[0] * a[1] << endl;
  }
  return 0;
}