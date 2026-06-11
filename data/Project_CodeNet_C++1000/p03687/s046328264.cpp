#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  string s;
  cin >> s;
  ll ans = INF;
  char c = s[0];
  bool flag = true;
  for (int i = 1; i < s.length(); i++) {
    if (s[i] != c) {
      flag = false;
      break;
    }
  }
  if (flag) {
    cout << 0 << endl;
    return 0;
  }
  for (char c = 'a'; c <= 'z'; c++) {
    ll cnt = 0;
    string t = s;
    while (t.length() > 1) {
      string new_t = "";
      ll c_cnt = 0;
      for (int i = 0; i < t.length() - 1; i++) {
        if (t[i] == c || t[i + 1] == c) {
          new_t += c;
          c_cnt++;
        } else {
          new_t += t[i];
        }
      }
      t = new_t;
      cnt++;
      if (c_cnt == t.length()) break;
    }
    ans = min(cnt, ans);
  }
  cout << ans << endl;
  return 0;
}