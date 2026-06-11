#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
int main() {
  string s;
  cin >> s;
  ll ans = 10000;
  for (char c = 'a'; c <= 'z'; c++) {
    int tmp = 0;
    int l = 0;
    REP(i, s.size()) {
      if (s[i] == c) {
        tmp = max(i - l, tmp);
        l = i + 1;
      }
    }
    tmp = max((ll)s.size() - l, (ll)tmp);
    ans = min(ans, (ll)tmp);
  }
  cout << ans << endl;
}
