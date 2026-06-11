#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
using namespace std;

signed main() {
  int n;
  cin >> n;

  int two = 0;
  int answer = 1;

  for (int i = 1; i <= n; i++) {
    int x = i;
    int cnt = 0;
    while(x % 2 == 0) {
      cnt++;
      x/=2;
    }
    if(cnt > two) {
      answer = i;
      two = cnt;
    }
  }
  cout << answer << '\n';
  return 0;
}