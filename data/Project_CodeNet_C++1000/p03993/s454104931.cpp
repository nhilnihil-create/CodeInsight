#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

int main() {
  cin >> n;
  a.resize(n);
  for (auto& p : a) {
    cin >> p;
    --p;
  }
  int res = 0;
  for (int i = 0; i < n; ++i) res += a[a[i]] == i;
  cout << res / 2 << endl;
  return 0;
}
