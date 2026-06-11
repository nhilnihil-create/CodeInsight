#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, ans = 0;

  cin >> n;

  vector<int> a;

  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    a.push_back(tmp);
  }

  for (int i = 0; i < n; i++) {
    if (a.at(i) != -1 && a.at(a.at(i) - 1) == i + 1) {
      ans++;
      a.at(a.at(i) - 1) = -1;
    }
  }

  cout << ans;

  return 0;
}