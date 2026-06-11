#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  long ans = 0;

  cin >> n;

  vector<int> a;

  for (int i = 0; i < n * 3; i++) {
    int tmp;
    cin >> tmp;
    a.push_back(tmp);
  }

  sort(a.begin(), a.end());

  int it = (int)a.size() - 2;

  for (int i = 0; i < n; i++) {
    ans += a.at(it);
    it -= 2;
  }

  cout << ans;

  return 0;
}