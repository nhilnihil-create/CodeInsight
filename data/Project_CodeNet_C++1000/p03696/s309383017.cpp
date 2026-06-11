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

  string ss1, ss2;
  rep(i, -min_v) ss1.push_back('(');
  rep(i, cur - min_v) ss2.push_back(')');
  s = ss1 + s + ss2;
  cout << s << endl;
  return 0;
}
