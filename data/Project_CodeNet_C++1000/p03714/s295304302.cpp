
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
  int N; std::cin >> N;
  std::vector<ll> a(3*N); rep(i, 3*N) std::cin >> a[i];

  std::vector<ll> b(3*N);
  std::priority_queue<ll, std::vector<ll>, std::greater<>> q;
  ll Sum = 0;
  rep(i,3*N) {
    if ( sz(q) != N ) {
      q.push(a[i]);
      Sum += a[i];
    }
    else {
      ll t = q.top();
      if ( t < a[i] ) {
        q.pop();
        q.push(a[i]);
        Sum -= t;
        Sum += a[i];
      }
    }
    b[i] = Sum;
  }

  Sum = 0;
  std::vector<ll> c(3*N);
  std::priority_queue<ll, std::vector<ll>, std::less<>> p;
  rep(i,3*N) {
    if ( sz(p) != N ) {
      p.push(a[3*N-i-1]);
      Sum += a[3*N-i-1];
    }
    else {
      ll t = p.top();
      if ( t > a[3*N-i-1] ) {
        p.pop();
        p.push(a[3*N-i-1]);
        Sum -= t;
        Sum += a[3*N-i-1];
      }
    }
    c[3*N-i-1] = Sum;
  }

  ll ans = -1e15;
  for(ll i=N-1; i<2*N; i++) ans = std::max(ans, b[i]-c[i+1]);
  std::cout << ans << std::endl;
  return 0;
}
