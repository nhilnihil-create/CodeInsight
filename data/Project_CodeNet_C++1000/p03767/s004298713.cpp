#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int64_t> v(3 * n);
  for (int i = 0; i < 3 * n; i++) {
    cin >> v.at(i);
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  int64_t s = 0;
  for (int i = 1; i < 2 * n; i += 2) {
    s += v.at(i);
  }
  cout << s << endl;
}