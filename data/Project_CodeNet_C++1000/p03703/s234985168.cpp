#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int maxn = 2e5 + 5, base = 131;
const ll llinf = 1e18;

int BIT[maxn];

void upd(int i, int v)
{
  for(; i < maxn; i += i & -i)
    BIT[i] += v;
}

int sum(int i)
{
  int res = 0;
  for(; i; i -= i & -i)
    res += BIT[i];
  return res;
}

signed main(void)
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifdef LOCAL
    freopen("A.INP", "r", stdin);
    freopen("A.OUT", "w", stdout);
  #endif // LOCAL
  int n, k; cin >> n >> k;
  vector<ll> a(n);
  for(auto & x : a) cin >> x, x -= k;
  for(int i = 1; i < n; ++i)
    a[i] += a[i - 1];
  vector<ll> v = a;
  v.pb(0);
  sort(v.begin(), v.end());
  for(auto & x : a){
    x = lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
  }
  int z = lower_bound(v.begin(), v.end(), 0) - v.begin() + 1;
  upd(z, 1);
  ll res = 0;
  for(auto & x : a){
    res += sum(x);
    upd(x, 1);
  }
  cout << res;
}
