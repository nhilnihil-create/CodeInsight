#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  rep(i, n) cin >> a.at(i);

  int cnt = 1;
  for (int i = 1; i < n; i++) {
    if (a.at(i) > a.at(i - 1)) {
      for (i; i < n; i++) {
        if (a.at(i) < a.at(i - 1)) {
          cnt++;
          break;
        }
      }
    } else if (a.at(i) < a.at(i - 1)) {
      for (i; i < n; i++) {
        if (a.at(i) > a.at(i - 1)) {
          cnt++;
          break;
        }
      }
    }
  }

  cout << cnt << endl;
  return 0;
}