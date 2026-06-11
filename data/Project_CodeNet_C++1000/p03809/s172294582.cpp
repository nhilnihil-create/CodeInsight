#include <bits/stdc++.h>
 
using namespace std;
 
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
 
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
 
//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define FF first
#define SS second
 
//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);

LL xs[100010];
LL dfs(VVI& G, int u, int p){
  if(SZ(G[u]) == 1){
	return xs[u];
  }

  LL as = 0;
  vector<LL> ch;
  for(int to: G[u]){
	if(to == p) continue;
	LL tmp = dfs(G, to, u);
	if(tmp < 0) return -1;
	as += tmp;
	ch.PB(tmp);
  }
  LL res = 2*xs[u] - as;
  if(!(0 <= res && res <= xs[u])) return -1;

  SORT(ch);
  if(SZ(ch) == 1){
	return res == as? res: -1;
  }
  
  ch.back() -= res;
  return (xs[u]-res >= ch.back()? res: -1);
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  REP(i,N) cin >> xs[i];
  VVI G(N);
  REP(i,N-1){
	int u, v;
	cin >> u >> v;
	--u;
	--v;
	G[u].PB(v);
	G[v].PB(u);
  }
  if(N == 2){
	cout << (xs[0] == xs[1]? "YES": "NO") << endl;
	return 0;
  }

  int r = -1;
  REP(i,N) if(SZ(G[i]) > 1) r = i;

  cout << (dfs(G, r, -1) == 0? "YES": "NO") << endl;
  
  return 0;
}
