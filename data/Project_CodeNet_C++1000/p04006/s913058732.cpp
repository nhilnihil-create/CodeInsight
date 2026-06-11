#include <bits/stdc++.h>

#define mp make_pair
#define eb emplace_back
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#ifdef ONPC
mt19937 rnd(228);
#else
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#endif


const int MAXN = 2003;
//#define int long long
const ll INF = 1e18;

ll dp[MAXN][MAXN];

void solve(){
  int n, x;
  cin >> n >> x;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  ll mn = INF;
  int ind = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] < mn) {
      mn = a[i];
      ind = i;
    }
  }

  memset(dp, 0x3f3f3f, sizeof dp);
  for (int i = 0; i < n; i++){
    dp[ind][i] = mn;
  }

  auto next = [&](int i){
    return (i + 1) % n;
  };

  auto prev = [&](int i){
    return (i - 1 + n) % n;
  };

  int i = next(ind);
  while (i != ind){
    ll mnv = INF;
    for (int k = 0; k < n; k++){
      mnv = min(mnv, a[(i - k + n) % n]);
      dp[i][k] = dp[prev(i)][k] + mnv;
    }
    i = next(i);
  }

  ll ans = INF;
  for (int i = 0; i < n; i++){
    ans = min(ans, dp[prev(ind)][i] + (ll)x * (ll)i);
  }

  cout << ans << '\n';
}

signed main()
{
    #ifdef FILEIO
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
