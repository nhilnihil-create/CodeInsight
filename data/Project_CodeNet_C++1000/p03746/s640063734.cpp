#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>
#include <complex>
#include <functional>

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
template<class T> inline T chmax(T & a, const T b) { return a = (a < b) ? b : a; }
template<class T> inline T chmin(T& a, const T b) { return a = (a > b) ? b : a; }

// type/const
#define int ll
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;
/* const int MOD = 1000000007; */
const int INF = 1e18;
const double PI = acos(-1);

using namespace std;

vector<vector<int>> graph;
vector<int> ans;
vector<bool> visited;

signed main() {
  int N, M;
  cin >> N >> M;

  int a, b;
  graph.resize(N);
  visited.resize(N, false);
  REP(i, M){
    cin >> a >> b;
    a--; b--;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }

  ans.emplace_back(0);
  ans.emplace_back(graph[0][0]);
  visited[0] = true;
  visited[graph[0][0]] = true;

  bool flag = true;
  while(flag){
    int v = ans[0];
    for(int i : graph[v]){
      if(visited[i] == false){
        ans.insert(ans.begin(), i);
        visited[i] = true;
        break;
      }
      if(i == graph[v].back()) flag = false;
    }
  }

  flag = true;
  while(flag){
    int v = ans.back();
    for(int i : graph[v]){
      if(visited[i] == false){
        ans.emplace_back(i);
        visited[i] = true;
        break;
      }
      if(i == graph[v].back()) flag = false;
    }
  }

  cout << ans.size() << endl;
  REP(i, ans.size()){
    cout << ans[i]+1; SPBR(i, ans.size());
  }

  return 0;
}