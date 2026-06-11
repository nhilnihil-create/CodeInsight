#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define freopen \
  if (0) freopen
#define cerr \
  if (0) cerr
#endif

#define fi first
#define se second

#define pb push_back
#define pp pop_back
#define mp make_pair

#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)

#define sqr(a) ((a)*1ll * (a))
#define sz(a) (int)a.size()
#define len(a) (int)a.length()
#define all(a) a.begin(), a.end()
#define nl '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pi;

const int inf = (int)1e9 + 7;
const int mod = (int)1e9 + 7;
const ll linf = (ll)1e18 + 7;

int to_digit(char ch) {
  return ch - '0';
}

ll calc(int mask, string &s) {
  ll sum = 0, cur = 0;
  rep(i, 0, len(s) - 1) {
    cur = cur * 10ll + to_digit(s[i]);
    if (i == len(s) - 1) continue;
    if ((1<<i) & mask) {
      sum += cur;
      cur = 0;
    }
  }
  sum += cur;
  return sum;
}

void solve() {
  int n;
  string s;
  cin >> s;
  n = len(s) - 1;

  ll res = 0;
  rep(mask, 0, (1<<n) - 1) {
    res += calc(mask, s);
  }

  cout << res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen(".in", "r", stdin);

  solve();

  return 0;
}
