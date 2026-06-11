#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    mp[x] += 1;
  }
  int ex = 0;
  for (auto &i : mp) {
    if (i.second > 1)
      ex += i.second - 1;
  }
  if (ex % 2 == 0) {
    cout << (int)mp.size() << endl;
  } else {
    cout << (int)mp.size() - 1 << endl;
  }
  return 0;
}
