#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> buttons(n);
  rep(i,n) cin >> buttons[i], buttons[i]--;

  int cur = 0, cnt = 0;
  vector<bool> seen(n, false);
  while (true) {
    if (cur+1 == 2) {
      cout << cnt << endl;
      return 0;
    }
    if (seen[cur]) {
      cout << -1 << endl;
      return 0;
    }
    cnt++;
    seen[cur] = true;
    cur = buttons[cur];
  }
  return 0;
}