#include <iostream>
#include <vector>
#define rep(S, L) for (int i = S; i < L; ++i)
using namespace std;

int main() {
  int n;
  cin >> n;
  int a[100] = {};
  int mi = 100;
  int ma = -100;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    mi = min(a[i], mi);
    ma = max(a[i], ma);
  }
  int d[202] = {};
  for (int i = mi; i <= ma; ++i) {
    for (int j = 0; j < n; ++j) {
      d[i + 100] += (a[j] - i) * (a[j] - i);
    }
  }
  int ans = 100000000;

  for (int i = mi; i <= ma; ++i) {
    if (d[i + 100] < ans) {
      ans = d[i + 100];
    }
  }
  cout << ans << endl;
  return 0;
}
