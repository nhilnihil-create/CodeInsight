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

int dp[(int)1e5 + 54][30];

void solve(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int l, Q;
  cin >> l >> Q;
  int x, y;

  for (int i = 0; i < 30; i++) dp[0][i] = -1;
  deque<int> q;
  q.eb(0);
  for (int i = 1; i < n; i++){
    while (a[q.front()] + l < a[i]) q.pop_front();
    //cerr << "DP " << i << " : ";
    dp[i][0] = q.front();
    //cerr << dp[i][0] << ' ';
    for (int j = 1; j < 30; j++){
      if (dp[i][j - 1] == -1) {
        dp[i][j] = -1;
        continue;
      }
      dp[i][j] = dp[dp[i][j-1]][j-1];
      //cerr << dp[i][j] << ' ';
    }
    //cerr << '\n';
    q.eb(i);
  }

  for (int i = 0; i < Q; i++){
    cin >> x >> y;
    x--, y--;

    if (x > y) swap(x, y);

    int ans = 0;
    int cur = y;
    while (cur > x){
    //cerr << cur << '\n';
      int f = 0;
      for (int j = 29; j > 0; j--){
        if (dp[cur][j] >= x){
          cur = dp[cur][j];
          ans += (1 << j);
          f = 1;
          break;
        }
      }
      if (f) continue;
      cur = dp[cur][0];
      ans++;
    }

    cout << ans << '\n';
  }
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
