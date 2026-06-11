#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int n, k;
  int l[50];
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> l[i];
  }
  sort(l, l + n, greater<int>());
  int ans = 0;
  for (int i = 0; i < k; i++) {
    ans += l[i];
  }
  cout << ans << endl;

  return 0;
}
