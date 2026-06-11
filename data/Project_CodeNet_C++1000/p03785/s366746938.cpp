#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  int n, c, k, bus = 0;
  cin >> n >> c >> k;
  int t[100001] = {0};
  for (int i = 0; i < n; i++) cin >> t[i];
  sort(t, t + n);
  for (int i = 0; i < n; i++) {
    int j;
    for (j = 0; j < c; j++) {
      if (i + j + 1 >= n) break;
      if (t[i] + k < t[i + j + 1]) break;
    }
    if (j == c) j--;
    i += j;
    bus++;
  }
  cout << bus << endl;
  return 0;
}