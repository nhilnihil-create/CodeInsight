#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

int main() {
  int n;
  string s;
  cin >> n >> s;
  int pre = 0;
  int now_pre = 0;
  REP(i, n) {
    if (s[i] == ')') {
      if (now_pre > 0) {
        now_pre--;
      } else {
        pre++;
      }
    } else {
      now_pre++;
    }
  }
  string pre_str(pre, '(');
  string suf_str(now_pre, ')');
  s.insert(0, pre_str);
  s.insert(s.length(), suf_str);
  cout << s << endl;
}