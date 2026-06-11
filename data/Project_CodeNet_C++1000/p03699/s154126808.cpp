#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  int n;
  cin >> n;
  vector<int> s(n);
  int point = 0;
  rep(i, n) {
    cin >> s[i];
    point += s[i];
  }

  if (point % 10 != 0) {
    cout << point << endl;
    return 0;
  }

  sort(s.begin(), s.end());

  int target = 0;
  while (target < n) {
    if (s[target] % 10 != 0) break;
    target++;
  }

  if (target >= n) {
    cout << 0 << endl;
  } else {
    cout << point - s[target] << endl;
  }

  return 0;
}