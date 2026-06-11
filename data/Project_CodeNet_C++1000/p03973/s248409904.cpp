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


const int MAXN = 100;
//#define int long long
const int INF = 1e9;

void solve(){
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  ll ans = a[0] - 1LL;
  ll cur = 2LL;
  for (int i = 1; i < n; i++){
    if (a[i] == cur) cur++;
    else if (a[i] > cur){
      ans += (a[i] - 1) / cur;
    }
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
