// by newbiechd
#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " = " << x << endl

const int N_MAX = 200003;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  if ((a[0] & 1) == 0 || (a[1] & 1) == 0 || (a[2] & 1) == 0) {
    cout << 0 << endl;
    return 0;
  }
  else {
    sort(a, a + 3);
    cout << 1ll * a[0] * a[1] << endl;
  }
  return 0;
}
