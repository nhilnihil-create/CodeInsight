#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define mt make_tuple

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int inf = 1LL<<60;
const int mod = 1e9 + 7;
const double eps = 1e-9;

/*{
}*/

vi g[2000];
vi dep(2000);

void dfs(int v, int p = -1)
{
  for(int e : g[v]){
    if(e == p) continue;
    dep[e] = dep[v] + 1;
    dfs(e, v);
  }
}

signed main()
{
  int n, k;
  cin >> n >> k;

  rep(i, n-1){
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].pb(b);
    g[b].pb(a);
  }

  int ans = n;
  if(k%2 == 0){
    rep(i, n){
      dep[i] = 0;
      dfs(i);

      int cnt = 0;
      rep(j, n) if(k/2 < dep[j]) cnt++;
      ans = min(ans, cnt);
    }
  }else{
    rep(i, n) for(int e : g[i]) if(i < e){
      dep[i] = dep[e] = 0;
      dfs(i, e);
      dfs(e, i);
  
      int cnt = 0;
      rep(j, n) if((k-1)/2 < dep[j]) cnt++;
      ans = min(ans, cnt);
    }
  }

  cout << ans << endl;

  return 0;
}
