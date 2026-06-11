#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>
#include <complex>
#include <functional>
#include <numeric>
#include <iomanip>

#define SPBR(w, n) std::cout<<(w + 1 == n ? '\n' : ' ');
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define ALL(i) (i).begin(), (i).end()
#define FOR(i, a, n) for(int i=(a);i<(n);++i)
#define RFOR(i, a, n) for(int i=(n)-1;i>=(a);--i)
#define REP(i, n) for(int i=0;i<int(n);++i)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define IN(a, x, b) (a<=x && x<b)
#define OUT(a, x, b) (x<a || b<=x)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define int ll
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;
/* const int MOD = 998244353; */
const int INF = 1e18;
const double PI = acos(-1);

using namespace std;
struct INIT { INIT(){
  cin.tie(0); ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
}}INIT;

int N; 
vector<int> dp;
vector<vector<int>> vec;
vector<vector<int>> graph;

void dfs(int u, int p = -1){
  for(auto v : graph[u]){
    if(v == p) continue;
    dfs(v, u);
  }

  if(vec[u].size() == 0){
    dp[u] = 1;
  }else{
    sort(ALL(vec[u]));

    REP(i, vec[u].size()){
      chmax(dp[u], vec[u][i]+(int)vec[u].size()-i);
    }
  }

  if(p != -1) vec[p].emplace_back(dp[u]);
}

signed main() {
  cin >> N;

  graph.resize(N);
  REP(i, N-1){
    int v;
    cin >> v; v--;
    graph[i+1].emplace_back(v);
    graph[v].emplace_back(i+1);
  }

  vec.resize(N);
  dp.resize(N);

  dfs(0);

  cout << dp[0]-1 << "\n";

  return 0;
}