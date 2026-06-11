// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
  int N, M;
  cin >> N >> M;
  int a, b;
  map<int, int> mp;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    if (mp.count(a))
      mp[a]++;
    else
      mp[a] = 1;
    if (mp.count(b))
      mp[b]++;
    else
      mp[b] = 1;
  }
  for (auto v : mp) {
    if (v.second % 2 == 1) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
