#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
#define FORV(i, v) for (auto i = v.begin(); i != v.end(); i++)
using namespace std;

typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1001001001;
const long long INFL = (1LL<<60);
const double eps = (1e-9);


int main() {
  string s;
  cin >> s;

  // a~z が j 番目以降に何個含まれるか
  vector<vector<int>> n(26, vector<int>(s.size() + 1, 0));

  for (int i = s.size() - 1; i >= 0; i--) {
    for (int j = 0; j < 26; j++) {
      if ('a' + j == s[i]) {
        n[j][i] = n[j][i+1] + 1;
      } else {
        n[j][i] = n[j][i+1];
      }
    }
  }

  ll ans = 1;  // 何もしない
  for (int i = 0; i < s.size() - 1; i++) {
    // i+1 から最後までの文字数から s[i] の数を引く
    ans += s.size() - (i+1) - n[s[i] - 'a'][i+1];
  }

  cout << ans << endl;

  return 0;
}
