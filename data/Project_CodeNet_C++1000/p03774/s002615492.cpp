#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<long long> a(n), b(n);
  vector<long long> c(m), d(m);
  for (int i=0; i<n; i++) {
    cin >> a[i];
    cin >> b[i];
  }
  for (int i=0; i<m; i++) {
    cin >> c[i];
    cin >> d[i];
  }

  for (int i=0; i<n; i++) {
    long long min_dist = LONG_LONG_MAX;
    int ans;
    for (int j=0; j<m; j++) {
      long long dist = abs(a[i]-c[j]) + abs(b[i]-d[j]);
      if (dist < min_dist) {
        min_dist = dist;
        ans = j+1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}