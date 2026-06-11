#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int n, a[100003], i;
string s;
int main() {
  cin >> n >> s;
  rep(i, 2) rep(j, 2) {
    a[1] = i, a[2] = j;
    a[0] = i ^ j ^ (s[1] == 'o');
    for (int k = 3; k < n; ++k) a[k] = a[k - 1] ^ a[k - 2] ^ (s[k - 1] == 'o');

    if ((s[n - 1] == 'o') == a[n - 2] ^ a[n - 1] ^ a[0] &&
        (s[0] == 'o') == a[n - 1] ^ a[0] ^ a[1]) {
      rep(k, n) cout << (a[k] ? 'S' : 'W');
      cout << endl;
      return 0;
    }
  }

  cout << -1 << endl;
  return 0;
}