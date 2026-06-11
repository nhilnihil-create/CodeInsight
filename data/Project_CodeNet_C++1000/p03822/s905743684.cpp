#include <bits/stdc++.h>
 
const double pi = 3.141592653589793238462643383279;
using namespace std;
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
 
 
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SQ(a) ((a)*(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
 
 
//repetition
//------------------------------------------
#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)
#define MOD 1000000007
 
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)

//ここから編集 

int a[100010];
vector<vector<int>> g(100010);
int sz[100010];

void dfs(int v){

  for(auto u: g[v]){
    
    dfs(u);
  }

  if(g[v].size() == 0){
  }else if(g[v].size() == 1){
    if(sz[g[v][0]] == 0){
      sz[v] = 1;
    }else{
      sz[v] = sz[g[v][0]] + 1;
    }
  }else{
  
    vector<int> vv;
    for(int i=0; i<g[v].size(); i++){
      vv.emplace_back(sz[g[v][i]]);
    }
    int t = g[v].size();
    int mx = 0;
    sort(all(vv));
    for(int i=0; i<g[v].size(); i++){
      mx = max(mx, t + vv[i]);
      t--;
    }
    sz[v] = mx;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  int N; cin >> N;

  for(int i=2; i<=N; i++) {
    cin >> a[i];
    g[a[i]].push_back(i);
  }

  dfs(1);
  cout << sz[1] << endl;
  return 0;
}
