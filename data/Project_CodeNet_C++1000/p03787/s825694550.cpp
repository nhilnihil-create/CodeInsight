#include <bits/stdc++.h>
 
#define pii pair<int, int>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long 
#define ull unsigned long long 
#define ld long double
#define sz(v) int(v.size())
#define all(v) v.begin(), v.end()
 
#define y1 what
 
using namespace std;
 
const int N = (int) 1e5 + 10;
const int M = (int) 101;
const ll big =  (1LL << 51);
const ll LINF = (ll) 1e18;
const int INF = (int) 1e9 + 7;
const int INF1 = (int) 1e9 + 3;
const double EPS = (double) 1e-6;
const double PI =  3.14159265359;
 
int n, m;
vector<int> v[N];
int u[N], clr[N];
int bad;
 
void dfs(int x, int c = 0) {
  u[x] = 1;
  clr[x] = c;
  for (auto it : v[x]) {
    if (!u[it]) 
        dfs(it, clr[x] ^ 1);
    else if (clr[x] == clr[it]) {
        bad = 1;
    }
  }
}
 
int main() {
    #define fn "balls"
    #ifdef witch
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
//        freopen(fn".in", "r", stdin);
//        freopen(fn".out", "w", stdout);
    #endif
    srand(time(0));
    cin >> n >> m;
    while (m--) {
      int x, y;
      cin >> x >> y;
      --x, --y;
      v[x].pb(y);
      v[y].pb(x);
    }
    ll isolated = 0, bipartite = 0, comp = 0;
    for (int i = 0; i < n; i++) {
      if (!u[i]) {
        if (v[i].empty()) {
            ++isolated;
        } else {
            bad = 0;
            dfs(i);
            bipartite += 1 - bad;
            comp++;
        }
      }
    }
    cerr << isolated << " " << bipartite << " " << (comp - bipartite) << endl;
    ll ans = bipartite * bipartite * 2;
    ans += isolated * (n - isolated) * 2;
    ans += isolated * isolated;
    ans += (comp - bipartite) * bipartite * 2;
    ans += (comp - bipartite) * (comp - bipartite);
    cout << ans;
    return 0;
}