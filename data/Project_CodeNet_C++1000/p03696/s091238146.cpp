#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  string s;
  cin >> n >> s;

  int min_v = 0;
  int cur = 0;
  rep(i, n) {
    cur += (s[i] == '(' ? +1 : -1);
    min_v = min(min_v, cur);
  }
  rep(i, -min_v) cout << '(';
  cout << s;
  rep(i, cur - min_v) cout << ')';
  cout << endl;
  return 0;
}
