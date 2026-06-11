#include<bits/stdc++.h>

#ifdef _PRINTDEBUG
  #include "lib/printdebug.hpp"
#else
  #define printdebug(...) 1
#endif
#define MOD_1_000_000_007 (1000000007)
#define IINF (1<<28)
#define LINF (1LL<<60)
#define rep(i, n)      REP(i, 0, (n))
#define repc(i, n)     REPC(i, 0, (n))
#define REP(i, n, m)   for (int i = (int)(n); i <  (int)(m); i++)
#define REPC(i, n, m)  for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
#define yesno(cond)       YESNO((cond), "Yes", "No")
#define YESNO(cond, a, b) cout << ((cond) ? (a) : (b)) << "\n"

namespace solver {
  using namespace std;
  typedef long long ll;

  string S;

  void init() {
    cin >> S;
  }

  bool sat(string s) {
    return unique(s.begin(), s.end()) - s.begin() == 1;
  }

  void solve() {
    int ans = 1000;
    rep(ci, S.size()) {
      char c = S[ci];
      string buffer = S;
      int cur = 0;
      while(1) {
        if(sat(buffer)) break;
        cur++;
        string T = buffer;
        buffer = "";
        rep(j, T.size()-1) {
          if(T[j] == c || T[j+1] == c) {
            buffer += c;
          } else {
            buffer += T[j];
          }
        }
      }
      ans = min(ans, cur);
    }
    cout << ans << "\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  solver::init();
  solver::solve();
  return 0;
}