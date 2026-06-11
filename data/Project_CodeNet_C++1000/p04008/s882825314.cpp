#include <bits/stdc++.h>
using namespace std;

using int32 = int_fast32_t;
using int64 = int_fast64_t;

const int32 INF = 1e9;
const int32 MOD = 1e9+7;
const int64 LLINF = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define POSSIBLE cout << ((n) ? "POSSIBLE\n" : "IMPOSSIBLE\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define ALL(obj) (obj).begin(),(obj).end()
#define pii pair<int32,int32>
#define pll pair<int64,int64>
#define pb(a) push_back(a)

int32 n,k;
vector<vector<int32>> to;
vector<int32> dist;
int32 ans = 0;

void dfs(int32 v, int32 d = 0){
  if(to[v].size() == 0){
    dist[v] = 0;
  }
  for(auto u : to[v]){
    dfs(u,d+1);
    dist[v] = max(dist[v], dist[u] + 1);
  }
  if(dist[v]== k-1 && d >= 2){
    ++ans;
    dist[v] = -1;
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> k;
  to.resize(n);
  REP(i,n){
    int32 a;
    cin >> a;
    a--;
    if(i == 0){
      if(a != 0)++ans;
    }else{
      to[a].push_back(i);
    }
  }
  dist.resize(n,-1);
  dist[0] = 0;
  dfs(0);
  // REP(i,n)ANS(dist[i]);
  ANS(ans);
  return 0;
}