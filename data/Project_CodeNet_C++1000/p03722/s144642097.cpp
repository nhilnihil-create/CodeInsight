
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <cmath>
#include <string>
#include <sstream>
#include <queue> 
#include <list>
#include <stack>
#include <unordered_map>
#include <algorithm> 
#include <numeric>  
#include <functional>
#include <cassert>
#include <bitset>
#include <cctype>  
#include <iomanip> 
#include <limits>  
#include <regex>
// std::numeric_limits<int>::max(), min()
// std::setprecision(X)
// std::islower(), std::isupper(), std::tolower, std::toupper
// std::accumulate(m.begin(), m.end(), 0LL);
// std::sort(begin(),end()) // 0, 1, 2, 3 ,4 (default, less);
// std::priority_queue<int, vector<int>, less<int>> que; // 4, 3, 2, 1 (defualt, less) : 
// if ( std::regex_match(S, std::regex("(dream|dreamer|erase|eraser)*")) ) std::cout << "YES" << std::endl;
 
#define rep(i, n) for(int i = 0; i < (int)(n);    i++)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<std::vector<int>> vvi;

ll gcd ( ll a, ll b ) { if ( b == 0 ) return a; else return gcd ( b, a%b ); }
ll lcm ( ll a, ll b ) { return a * b / gcd(a, b); }


int main (void) {
  std::cin.tie(0);  std::ios::sync_with_stdio(false);
  int N, M; std::cin >> N >> M;
  struct Edge {
    int from;
    int to;
    ll cost;
  };
  std::vector<Edge> G;
  std::vector<ll> d(N, -1e15); d[0] = 0;
  rep(i,M) {
    int a, b;
    ll c; std::cin >> a >> b >> c;
    a--, b--;
    G.push_back( { a, b, c } );
  }

  rep(i,N) rep(j,sz(G)) {
    auto&& e = G[j];
    if ( d[e.from] == -1e15 ) continue;
    if ( d[e.to] < d[e.from] + e.cost ) {
      d[e.to] = d[e.from] + e.cost;
    }
  }


  ll ans = d[N-1];
  std::vector<bool> negative(N);
  rep(i,N) rep(j,sz(G)) {
    auto&& e = G[j];
    if ( d[e.from] == -1e15 ) continue;
    if ( d[e.to] < d[e.from] + e.cost ) {
      d[e.to] = d[e.from] + e.cost;
      negative[e.to] = true;
    }
    if ( negative[e.from] ) negative[e.to] = true;
  }



  if ( negative[N-1] ) std::cout << "inf" << std::endl;
  else std::cout << ans << std::endl;
  return 0;
}
