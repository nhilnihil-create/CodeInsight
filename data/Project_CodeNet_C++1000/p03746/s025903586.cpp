#include <bits/stdc++.h>
using namespace std;

typedef int_fast32_t int32;
typedef int_fast64_t int64;

const int32 inf = 1e9+7;
const int32 MOD = 1000000007;
const int64 llinf = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define POSSIBLE(n) cout << ((n) ? "POSSIBLE\n" : "IMPOSSIBLE\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define all(obj) (obj).begin(),(obj).end()
#define rall(obj) (obj).rbegin(),(obj).rend()
#define fi first
#define se second
#define pb(a) push_back(a)
typedef pair<int32,int32> pii;
typedef pair<int64,int64> pll;

template<class T> inline bool chmax(T& a, T b) {
  if (a < b) { a = b; return true; } return false;
}
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) { a = b; return true; } return false;
}

int32 n,m;
vector<vector<int32>> adj;
vector<int32> ans,ans2;
vector<bool> visited;

void dfs(int32 v){
  ans.pb(v);
  visited[v] = true;
  for(auto u : adj[v]){
    if(visited[u])continue;
    dfs(u);
    break;
  }
}
void dfs2(int32 v){
  if(v != 0)
    ans2.pb(v);
  visited[v] = true;
  for(auto u : adj[v]){
    if(visited[u])continue;
    dfs2(u);
    break;
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  adj.resize(n);
  REP(i,m){
    int32 a,b;
    cin >> a >> b;
    --a;--b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  visited.resize(n,false);
  dfs(0);
  dfs2(0);
  ANS(ans.size() + ans2.size());
  reverse(all(ans2));
  for(auto a : ans2)cout << a+1 << " ";
  for(auto a : ans)cout << a+1 << " ";
  cout << endl;
  return 0;
}