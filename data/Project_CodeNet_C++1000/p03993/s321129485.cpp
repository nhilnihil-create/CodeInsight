#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    a--;
    m[i] = a;
  }
  int cnt = 0;
  for (auto mm : m) {
    if (m[mm.second] == mm.first) cnt++;
  }

  cout << cnt / 2 << endl;
}