#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int prev = a[0], r = 0, ans = n;
  for (int i = 1; i < n; i++) {
    if (a[i] == prev) {
      r ^= 1;
      ans--;
    }
    prev = a[i];
  }
  cout << ans - r << endl;
}