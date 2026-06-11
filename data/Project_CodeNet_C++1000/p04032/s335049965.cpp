#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
const ll MAX = 2*(ll)pow(10, 5);
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s; cin >> s;
  bool flag = 1;
  rep(i, s.size()-1) {
    if (s.at(i) == s.at(i+1)) {
      cout << i+1 << ' ' << i+2 << endl;
      flag = 0;
      break;
    }
  }
  if (flag) {
    rep(i, s.size()-2) {
      if (s.at(i) == s.at(i+2)) {
        cout << i+1 << ' ' << i+3 << endl;
        flag = 0;
        break;
      }
    }
  }
  if (flag) cout << -1 << ' ' << -1 << endl;
}
