#include <bits/stdc++.h>
#define int long long
#define uint unsigned int
#define rep(i, a, n) for (int i = a; i < n; i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (a).size()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define MT make_tuple
#define dump(x) cerr << #x << " = " << (x) << endl;
#define dumpi(i, x) cerr << string((i), ' ') << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
using namespace std;
using pii = pair<int, int>;
constexpr int MOD = 1000000007;
constexpr int INF = 1LL << 30;
constexpr double EPS = 1e-10;

int N, T;
int A[100010];

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  cin >> N >> T;
  int mn = INF;
  vector<int> v;
  rep(i, 0, N) {
    cin >> A[i];
    mn = min(mn, A[i]);
    v.EB(A[i]-mn);
  }
  sort(all(v));
  reverse(all(v));
  int ans = 0;
  rep(i, 0, sz(v)) {
    if (v[i] == v[0]) ans++;
  }
  cout << ans << endl;

  return 0;
}