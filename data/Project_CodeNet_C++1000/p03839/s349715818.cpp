#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
//#define int long long int
const int MOD = 1000000007;
const ll LINF = (ll)1e18 - 1;
const int INF = 1e9 - 1;
const double EPS = 0.000000001;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void print(const vector<int> &v) {
  for(auto x : v) {
    cout << x << " ";
  }
  cout << endl;
}

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  VL a(n), b(n+1, 0), c(n+1, 0);
  rep(i, n){
    cin >> a[i];
  }
  rep(i, n) {
    b[i+1] = b[i] + a[i];
    c[i+1] = c[i] + max<ll>(0, a[i]);
  }
  ll ans = -LINF;
  for(int i = 0; i + k <= n; ++i) {
    ll left = c[i] - c[0];
    ll right = c[n] - c[i + k];
    if(b[i + k] - b[i] >= 0) {
      ans = max<ll>(ans, b[i + k] - b[i] + left + right);
    }
    else {
      ans = max<ll>(ans, left + right);
    }
  }
  out(ans);

  return 0;
}
