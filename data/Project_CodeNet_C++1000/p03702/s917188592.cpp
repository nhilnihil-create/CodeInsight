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
  int n;
  ll a, b;
  cin >> n >> a >> b;
  VL h(n);
  rep(i, n) cin >> h[i];
  ll hmax = *max_element(all(h));
  ll left = 0;
  ll right = hmax + 1;
  ll ans;
  while(right - left > 1) {
    ll mid = (right + left) / 2;
    ll count = 0;
    rep(i, n) {
      if(mid * b >= h[i]) continue;
      count += (ll)ceil((double)(h[i] - mid * b) / (double)(a - b));
    }
    if(count <= mid){
      right = mid;
      ans = mid;
    }
    else {
      left = mid;
    }
  }
  out(ans);
  return 0;
}
