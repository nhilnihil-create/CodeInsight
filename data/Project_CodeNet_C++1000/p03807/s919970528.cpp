#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
  int n, a, cnt = 0;
  cin >> n;
  rep(i, n) {
    cin >> a;
    if (a % 2 == 1) cnt++;
  }

  cout << (cnt % 2 ? "NO" : "YES") << endl;
  return 0;
}
