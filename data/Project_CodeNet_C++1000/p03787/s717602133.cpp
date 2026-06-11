#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define each(a,x) for(auto a : (x))
#define all(a) (a).begin(),(a).end()
#define chmin(a,b) ((a) = min((a),(b)))
#define chmax(a,b) ((a) = max((a),(b)))
#define in_range(x,l,r) ((l)<=(x) && (x)<(r))
#define printvec(a) rep(i,a) cout << a[i] << " \n"[i+1==(a).size()];
#define fs first
#define sc second
#define em emplace
#define eb emplace_back
#define sz size()
#define MP make_pair
using namespace std;
typedef long long ll;
typedef double D;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;

const ll INF = 1e8;
const D EPS = 1e-8;
const ll MOD = 1e9+7;

int dfs(int v, int p, int d, vi &used, const vector<vi> &g){
  if(g[v].size() == 0) return 0;

  if(used[v]>=0){
    if(used[v] == used[p]) return 1;
    else return 2;
  }
  used[v] = d;

  int ans = 2;
  for(int u : g[v]){
    if(u == p) continue;
    int tmp = dfs(u,v,1-d,used,g);
    ans = min(ans, tmp);
  }
  return ans;
}

int main(){
  ll n, m;
  cin >> n >> m;
  vector<vi> g(n);
  rep(i,m){
    int a,b;
    cin >> a >> b;
    a--; b--;
    g[a].eb(b); g[b].eb(a);
  }

  vl cnt(3,0);
  vi used(n,-1);
  rep(v,n){
    if(used[v]==-1){
      cnt[dfs(v,-1,0,used,g)]++;
    }
  }

  ll ans = 0;
  while(cnt[0]){
    ans += 2ll*n - 1ll;
    n--; cnt[0]--;
  }

  cout << ans + cnt[1]*cnt[1] + 2ll*cnt[1]*cnt[2] + 2ll*cnt[2]*cnt[2] << endl;
}
