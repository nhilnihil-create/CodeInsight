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
const int INF = 1e9;

vector<int> g[MAXN];
           
void solve(){
  int n, k;
  cin >> n >> k;

  vector<pair<int, int>> e;
  for (int i = 0; i < n-1; i++){
      int a, b;
      cin >> a >> b;
      a--, b--;
      g[a].eb(b);
      g[b].eb(a);
      e.eb(a, b);
  }

  auto bfs = [&](int v1, int v2 = -1){
    deque<int> q;
    vector<int> d(n, INF);
    q.eb(v1);
    d[v1] = 0;
    if (v2 != -1){
      d[v2] = 0;
      q.eb(v2);
    }
    while (!q.empty()){
      int v = q.front();
      q.pop_front();
      for (auto i : g[v]){
        if (d[i] > d[v] + 1){
          d[i] = d[v] + 1;
          q.eb(i);
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) if (d[i] > (k >> 1)) ans++;
    return ans;
  };

  int ans = INF;
  if (k % 2 == 0)
  for (int i = 0; i < n; i++){
    ans = min(ans, bfs(i));
  }
  else
  for (int i = 0; i < n-1; i++){
    ans = min(ans, bfs(e[i].ff, e[i].ss));
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
