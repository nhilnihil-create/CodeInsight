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

struct ed {
  int a, b, c;
  ed() {}
  ed(int aa, int bb, int cc){
    a = aa;
    b = bb;
    c = cc;
  }

  int get(int u){
    if (u == a) return b;
    return b;
  }
};

int n, m;
vector<int> g[MAXN];
int d[MAXN][MAXN];
vector<ed> e;

void read(){
  cin >> n >> m;
  int a, b, c;
  memset(d, 0x3f, sizeof d);
  for (int i = 0; i < n; i++) d[i][i] = 0;
  for (int i = 0; i < m; i++){
    cin >> a >> b >> c;
    a--, b--;
    g[a].eb(i);
    g[b].eb(i);
    e.eb(a, b, c);
    d[a][b] = c;
    d[b][a] = c;
  }
}

void floyd(){
  for (int k = 0; k < n; k++){
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

void solve(){
  read();

  floyd();

  int ans = 0;
  for (auto ei: e){
    int f = 1;
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        if (i == j) continue;

        //cerr << d[i][j] << ' ' << i << ' ' << j << ' ' << d[i][ei.a] + ei.c + d[ei.b][j] << '\n';
        if (d[i][ei.a] + ei.c + d[ei.b][j] <= d[i][j]) f = 0;
      }
    }
    ans += f;
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
