#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int r = 0;
  vector<bool> memo(8);
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    if (a >= 3200) {
      r++;
    }
    else {
      int c = 0;
      while (true) {
        a -= 400;
        c++;
        if (a < 0) {
          break;
        }
      }
      memo.at(c - 1) = true;
    }
  }
  int ans = 0;
  for (int i = 0; i < 8; i++) {
    if (memo.at(i)) {
      ans++;
    }
  }
  if (ans == 0) {
    cout << ans + 1 << " ";
  }
  else {
    cout << ans << " ";
  }
  cout << ans + r << endl;
}