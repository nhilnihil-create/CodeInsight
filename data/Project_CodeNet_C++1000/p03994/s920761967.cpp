#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
#define all(obj) (obj).begin(), (obj).end()
static const int dx[4] = {0, 1, 0, -1};
static const int dy[4] = {1, 0, -1, 0};
static const char dir[4] = {'u', 'r', 'd', 'l'};
static const ll INF = 1 << 21;
static const ll MOD = 1e9 + 7;

signed main() {
  string s;
  cin >> s;
  int K;
  cin >> K;

  int cur = 0;
  while (cur != (int)s.size()) {
    if (s[cur] != 'a' && 'z' - s[cur] + 1 <= K) {
      K -= 'z' - s[cur] + 1;
      s[cur] = 'a';
    }
    ++cur;
  }
  K %= 26;
  while (K && 0 < cur && cur <= (int)s.size()) {
    while (s[cur - 1] != 'z' && K) {
      s[cur - 1]++;
      K--;
    }
    cur--;
  }
  cout << s << endl;
  return 0;
}