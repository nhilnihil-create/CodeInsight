#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <set>
using namespace std;
typedef long long ll;

int main() {
  int n, m;
  cin >> n >> m;

  ll a[51], b[51], c[51], d[51];

  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> c[i] >> d[i];
  }

  for (int i = 0; i < n; i++) {
    ll min = 1000000001;
    int ans;
    for (int j = 0; j < m; j++) {
      if (min > abs(a[i] - c[j]) + abs(b[i] - d[j])) {
        min = abs(a[i] - c[j]) + abs(b[i] - d[j]);
        ans = j+1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}