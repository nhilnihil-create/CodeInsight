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
  int n;
  cin >> n;
  int t[110];
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  int m;
  cin >> m;

  int p[110], x[110];
  for (int i = 0; i < m; i++) {
    cin >> p[i] >> x[i];
  }

  for (int i = 0; i < m; i++) {
    int ans = 0;
    for (int j = 0; j < n; j++) {
      if (j == (p[i]-1)) {
        ans += x[i];
      } else {
        ans += t[j];
      }
    }
    cout << ans << endl;
  }
  return 0;
}