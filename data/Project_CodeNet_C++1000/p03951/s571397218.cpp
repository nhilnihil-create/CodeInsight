#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Edge {
  ll to;
  ll cost;
};
int main() {
  int N;
  string s, t;
  cin >> N >> s >> t;
  vector<char> a;
  REP(i, N) a.push_back(s[i]);
  REP(i, N) a.push_back(t[i]);
  ll ans = s.size() + t.size();
  REP(i, N) {
    bool check = true;
    a.erase(a.begin() + N);
    REP(j, N) {
      if (a[i] != s[i]) check = false;
    }
    REP(j, N) {
      if (t[N - 1 - j] != a[a.size() - 1 - j]) {
        check = false;
      }
    }
    if (check) ans = a.size();
  }
  cout << ans << endl;
}