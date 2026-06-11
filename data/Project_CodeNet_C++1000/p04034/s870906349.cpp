#include <bits/stdc++.h>

#define mp make_pair
#define eb emplace_back
#define x first
#define y second

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
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> a(m);
  for (int i = 0; i < m; i++) cin >> a[i].x >> a[i].y;

  vector<int> cnt(n, 1);
  vector<int> u(n, 0);
  u[0] = 1;

  for (int i = 0; i < m; i++){
    u[a[i].y - 1] |= u[a[i].x - 1];
    if (cnt[a[i].x - 1] == 1) u[a[i].x - 1] = 0;
    cnt[a[i].x - 1]--;
    cnt[a[i].y - 1]++;
  }

  int ans = 0;
  for (int i = 0; i < n; i++) ans += u[i];
  
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
