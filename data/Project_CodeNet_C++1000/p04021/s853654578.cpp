#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, n) for (int i = l; i < (n); ++i)
#define sz(v) (int)v.size()
const int inf = 1e9 + 7;
const ll INF = 1e18;
#define abs(x) (x >= 0 ? x : -(x))
#define lb(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define ub(v, x) (int)(upper_bound(all(v), x) - v.begin())
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<typename T> T pow(T a, int b) { return b ? pow(a * a, b / 2) * (b % 2 ? a : 1) : 1; }
const int mod = 1000000007;
ll modpow(ll a, int b) { return b ? modpow(a * a % mod, b / 2) * (b % 2 ? a : 1) % mod : 1; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& vec) { rep(i, sz(vec)) { if (i) os << " "; os << vec[i]; } return os; }
template<class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p) { os << p.F << " " << p.S; return os; }
template<class T> inline void add(T &a, int b) { a += b; if (a >= mod) a -= mod; }



void solve();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);

  int T;
  // cin >> T;
  T = 1;

  while (T--) {
      solve();
  }
}

// 0 indexed
int n;
int bit[1000010];
void add(int a, int w) {
  for (int x = a; x < n; x |= x + 1) bit[x] += w;
}
int sum(int a) { // [0, a)
  int ret = 0;
  for (int x = a - 1; x >= 0; x = (x & (x + 1)) - 1) {
    ret += bit[x];
  }
  return ret;
}


// youtube editorial
void solve() {
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<int> d = a;
  sort(all(d));

  map<int, int> mp;
  rep(i, n) mp[d[i]] = i;
  // for (auto e : mp) cout << e.F << " " << e.S << endl;

  int cnt = 0;
  rep(i, n) if (i % 2 != mp[a[i]] % 2) cnt++;
  cout << cnt / 2 << endl;
}
