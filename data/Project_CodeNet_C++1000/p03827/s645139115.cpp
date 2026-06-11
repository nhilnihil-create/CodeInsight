#include <bits/stdc++.h>
#define rep(i, ns, ne) for (int i = ns; i < ne; ++i)
using namespace std;

int main() {
  int N;
  int x = 0;
  int ans = 0;
  string s;
  cin >> N >> s;
  rep(i, 0, N) {
    if (s[i] == 'I') {
      x++;
    } else {
      x--;
    }
    ans = max(ans, x);
  }
  cout << ans << endl;
  getchar();
}