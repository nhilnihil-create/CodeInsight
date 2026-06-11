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


signed main() {
  string s, t;
  cin >> s >> t;

  int N = s.size(), M = t.size();
  vector<int> sum1(N+1), sum2(M+1);
  sum1[0] = 0; sum2[0] = 0;

  FOR(i, 1, N+1){
    if(s[i-1] == 'A') sum1[i] = sum1[i-1]+1;
    else sum1[i] = sum1[i-1]+2;
  }
  FOR(i, 1, M+1){
    if(t[i-1] == 'A') sum2[i] = sum2[i-1]+1;
    else sum2[i] = sum2[i-1]+2;
  }

  int q;
  cin >> q;

  int a, b, c, d;
  REP(i, q){
    cin >> a >> b >> c >> d;
    int x = (sum1[b]-sum1[a-1])%3;
    int y = (sum2[d]-sum2[c-1])%3;
    if(x == y) YES;
    else NO;
  }

  return 0;
}