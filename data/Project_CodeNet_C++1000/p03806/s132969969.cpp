
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

vi a, b, c; 
std::vector<vvi> dp;
int sol(int n, int x, int y) {
  if ( n < 0 && x == 0 && y == 0 ) return 0;
  if ( n < 0 ) return 1e8;
  if ( dp[n][x][y] != 1e7 ) return dp[n][x][y];

  if ( x - a[n] >= 0 && y-b[n] >= 0 ) {
    dp[n][x][y] = std::min( sol(n-1,x,y), sol(n-1,x-a[n],y-b[n])+c[n] );
  }
  else dp[n][x][y] = sol(n-1,x,y);
  return dp[n][x][y];
}

int main (void) {
  std::cin.tie(0);  std::ios::sync_with_stdio(false);
  int N, Ma, Mb; std::cin >> N >> Ma >> Mb;
  a.resize(N); b.resize(N); c.resize(N);
  rep(i,N) std::cin >> a[i] >> b[i] >> c[i];

  dp.resize(N+1); 
  rep(i,N+1) dp[i].resize(401); 
  rep(i,N+1) rep(j,401) dp[i][j].resize(401, 1e7);

  int ans = 1e7;
  for(int i=1; i<=400; i++) for(int j=1; j<=400; j++) {
    if ( j*Ma != i*Mb ) continue;
    ans = std::min(ans, sol(N-1, i, j));
  }
  if ( ans == 1e7 ) std::cout << -1 << std::endl;
  else std::cout << ans << std::endl;
  return 0;
}
