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


const int MAXN = 100100;
//#define int long long
const int INF = 1e9;

vector<int> g[MAXN];
int d[MAXN];
int blocked[MAXN];

void dfs(int v, int dh=0){
  d[v] = dh;
  for (auto i : g[v]) if (!blocked[i]) dfs(i, dh+1);
}

void solve(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i =0 ; i < n; i++){
    cin >> a[i];
    a[i]--;
  }
  int ans = 0;
  if (a[0] != 0) {
    ans++;
    a[0] = 0;
  }
  for (int i = 1; i < n; i++){
    g[a[i]].eb(i);
  }

  dfs(0);

  priority_queue<pair<int, int>> q;
  for (int i = 1; i < n; i++) q.push(mp(d[i], i));

  while (!q.empty()){
    auto cur = q.top();
    int i = cur.ss;
    q.pop();

    if (d[i] <= k) continue;

    int it = 1;
    while (it < k) {
      i = a[i];
      it++;
    }

    dfs(i, 1);
    blocked[i] = 1;
    ans++;
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
