#include "bits/stdc++.h"
using namespace std;

int main() {
  int n;
  cin >> n;
  int odd = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a % 2 == 1) odd++;
  }
  string ans = "YES";
  if (odd % 2 != 0) ans = "NO";
  cout << ans << endl;
}
