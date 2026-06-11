#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define FOR(i, b, n) for (ll i = b; i < n; ++i)

using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve(string s) {
  ll N = s.length();

  set<char> cand;
  REP(i, N)
    cand.emplace(s[i]);

  if (cand.size() == 1) {
    // printf("string with one char\n");
    cout << 0 << endl;
    return;
  }

  ll ans(N);
  for (const char c : cand) {
    string t(s);
    // printf("start c=%c\n", c);
    REP(i, N) {
      bool finish(true);
      REP(j, N - i - 1) {
	if (t[j] == c)
	  continue;
	else if (t[j + 1] == c)
	  t[j] = c;
	else
	  finish = false;
      }
      // printf("%s\n",t.substr(0, N - i - 1).c_str());
      if (finish) {
	// printf("ans = %lld\n", i);
	ans = min(ans, i + 1);
	break;
      }
    }
  }
  cout << ans << endl;
}

int main(){
  // int 3E4  long 2E9  ll 9E18
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  solve(s);

  return 0;
}
