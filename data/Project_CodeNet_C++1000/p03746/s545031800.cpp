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

// output
#define SPBR(w, n) std::cout<<(w + 1 == n ? '\n' : ' ');
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
// utility
#define ALL(i) (i).begin(), (i).end()
#define FOR(i, a, n) for(int i=(a);i<(n);++i)
#define RFOR(i, a, n) for(int i=(n)-1;i>=(a);--i)
#define REP(i, n) for(int i=0;i<int(n);++i)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define IN(a, x, b) (a<=x && x<b)
#define OUT(a, x, b) (x<a || b<=x)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// type/const
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


signed main() {
  int N, M; 
  cin >> N >> M;

  vector<vector<int>> graph(N);
  REP(i, M){
    int u, v;
    cin >> u >> v;
    u--; v--;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }

  set<int> s;
  s.insert(0);
  s.insert(graph[0][0]);

  auto f = [&](int next, vector<int> &ans){
    while(1){
      int v = next;
      bool flag = true;
      for(auto u : graph[v]){
        if(!s.count(u)){
          flag = false;
          next = u;
        }
      }
      if(flag) break;
      ans.emplace_back(next);
      s.insert(next);
    }
  };

  vector<int> ri;
  ri.emplace_back(0);

  vector<int> le;
  le.emplace_back(graph[0][0]);
  f(0, ri);

  f(graph[0][0], le);

  cout << ri.size()+le.size() << "\n";
  RREP(i, le.size()){
    cout << le[i]+1 << " ";
  }
  REP(i, ri.size()){
    cout << ri[i]+1; SPBR(i, ri.size());
  }


  return 0;
}