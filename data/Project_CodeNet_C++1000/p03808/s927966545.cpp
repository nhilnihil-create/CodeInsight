#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define fst first
#define snd second
#define ALL(obj) (obj).begin(), (obj).end()
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
//#define int long long int
const int MOD = 1000000007;
const ll LINF = (ll)1e18 - 1;
const int INF = 1e9 - 1;
const double EPS = 0.000000001;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  cin >> n;
  VL a(n), d(n);
  ll sum = 0;
  rep(i, n)
  {
    cin >> a[i];
    sum += a[i];
  }
  ll de = (n * (n + 1) / 2);
  ll k = sum / de;

  rep(i, n - 1) d[i] = a[i + 1] - a[i] - k;
  d[n - 1] = a[0] - a[n - 1] - k;

  bool ans = true;

  if (sum % de != 0)
  {
    ans = false;
  }

  rep(i, n)
  {
    if (d[i] < 0 && d[i] % n == 0)
    {
      k -= -d[i] / n;
    }
    else if (d[i] == 0)
    {
      continue;
    }
    else
    {
      ans = false;
    }
  }
  puts(ans && (k == 0) ? "YES" : "NO");

  return 0;
}
