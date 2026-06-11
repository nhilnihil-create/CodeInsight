#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

int main() {
  string s;
  int k;
  cin >> s;
  cin >> k;
  string str = "bcdefghijklmnopqrstuvwxyza";
  string str2 = "abcdefghijklmnopqrstuvwxyz";
  int len = s.size();
  REP(i, len) {
    int cnt = 25 - str.find(s[i]);
    if (cnt <= k) {
      s[i] = 'a';
      k -= cnt;
    }
  }

  if (k > 0) {
    k %= 26;
    char _c = str2[str2.find(s[len - 1]) + k];
    s[len - 1] = _c;
  }

  cout << s << endl;
}