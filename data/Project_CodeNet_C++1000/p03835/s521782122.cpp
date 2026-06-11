#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int k, s;
  cin >> k >> s;

  int count = 0;
  for (int x = 0; x <= k; x++) {
    for (int y = 0; y <= k; y++) {
      if (s - (x + y) >= 0 && s - (x + y) <= k) count++;
    }
  }

  cout << count << endl;
}