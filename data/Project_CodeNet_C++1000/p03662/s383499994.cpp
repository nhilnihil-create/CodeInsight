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
const int INF = 1e18;

using namespace std;

vector<int> dijkstra(int i,int n, vector<vector<pair<int, int>>> graph) {
  vector<int> d(n, INF);
  d[i] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  q.push(make_pair(0, i));
  while (!q.empty()) {
    pair<int, int> p = q.top();
    q.pop();
    int v = p.second;
    if (d[v] < p.first) {
      continue;
    }
    for (auto x : graph[v]) {
      if (d[x.first] > d[v] + x.second) {
        d[x.first] = d[v] + x.second;
        q.push(pair<int, int>(d[x.first], x.first));
      }
    }
  }
  return d;
}

signed main() {
  int N;
  cin >> N;
  
  vector<vector<pair<int, int>>> vec(N);
  int a, b;
  REP(i, N-1){
    cin >> a >> b;
    a--; b--;
    vec[a].push_back(make_pair(b, 1));
    vec[b].push_back(make_pair(a, 1));
  }

  vector<int> dist1 = dijkstra(0, N, vec);
  vector<int> dist2 = dijkstra(N-1, N, vec);

  int ans = 0;
  REP(i, N){
    if(dist1[i] <= dist2[i]) ans++;
    else ans--;
  }

  if(ans > 0) cout << "Fennec" << endl;
  else cout << "Snuke" << endl;

  return 0;
}