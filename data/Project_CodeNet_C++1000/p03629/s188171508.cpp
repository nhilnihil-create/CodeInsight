#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) (v).begin(), (v).end()
#define resz(v, ...) (v).clear(), (v).resize(__VA_ARGS__)
#define reps(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep(i, n) reps(i, 0, n)

template<class T1, class T2> void chmin(T1 &a, T2 b){if(a>b)a=b;}
template<class T1, class T2> void chmax(T1 &a, T2 b){if(a<b)a=b;}

using Pi = pair<int, int>;
using Tapris = tuple<int, int, int>;
using vint = vector<int>;

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  string s;
  cin >> s;
  string t = s;
  t += '$';
  reverse(all(t));
  int n = t.size();
  vint dp(n+1, inf);
  vint last(26, 0);
  vector<Pi> rev(n+1);
  dp[0] = 0;
  dp[1] = 1;
  rev[0] = Pi(-1, 0);
  rev[1] = Pi(-1, 'a');
  reps(i, 1, n) {
    last[t[i]-'a'] = i;
    rep(j, 26) {
      if(dp[i+1] > dp[last[j]]+1) {
	dp[i+1] = dp[last[j]]+1;
	rev[i+1] = Pi(last[j], 'a'+j);
      }
    }
  }
  int idx = n;
  while(idx > 0) {
    cout << (char)rev[idx].second;
    idx = rev[idx].first;
  }
  cout << endl;

  return 0;
}
