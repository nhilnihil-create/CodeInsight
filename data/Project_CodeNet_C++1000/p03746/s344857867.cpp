#include <bits/stdc++.h> 
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
        #define eprintf(...) 42
#endif

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(x) (x).begin(),(x).end()
#define foreach(u,v) for(auto (u) : (v))
#define pb push_back
#define mp make_pair
#define mt make_tuple

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;

const int inf = 1e9;
const ll linf = 1LL<<60;
const ll mod = 1e9 + 7;
const double eps = 1e-9;

/*
*/
int n, m;
vector<int> g[100000];
vector<int> ans;
bool used[100000];

void dfs(int x)
{
  used[x] = true;
  ans.pb(x);

  for(auto e: g[x]){
    if(!used[e]){
      dfs(e);
      break;
    }
  }
}

int main()
{
  cin >> n >> m;

  int sa, sb;
  cin >> sa >> sb;
  sa--; sb--;
  rep(i, m-1){
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].pb(b);
    g[b].pb(a);
  }

  used[sa] = used[sb] = true;

  dfs(sa);
  reverse(all(ans));
  dfs(sb);

  cout << ans.size() << endl;
  rep(i, ans.size()){
    cout << ans[i]+1 << " \n"[i == ans.size()-1];
  }

  return 0;
}
