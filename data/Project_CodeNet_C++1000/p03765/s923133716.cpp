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

int f(int a, int b){
  b = b-a;
  a %= 3; b %= 3;
  int aa = 0, bb = 0;
  if(a == 1) aa++;
  if(a == 2) bb++;
  if(b == 1) bb++;
  if(b == 2) aa++;
  
  if(aa == 0){
    if(bb == 0) return 0;
    if(bb == 1) return 2;
    if(bb == 2) return 1;
  }
  if(aa == 1){
    if(bb == 0) return 1;
    if(bb == 1) return 0;
    if(bb == 2) return 2;
  }
  if(bb == 0) return 2;
  if(bb == 1) return 1;
  return 3;
}

signed main() {
  string s, t; 
  cin >> s >> t;

  int N = s.size();
  int M = t.size();
  vector<int> ss(N+1, 0);
  vector<int> tt(M+1, 0);

  REP(i, N) ss[i+1] += ss[i]+((s[i] == 'A')? 1: 0);
  REP(i, M) tt[i+1] += tt[i]+((t[i] == 'A')? 1: 0);

  int q;
  cin >> q;

  REP(i, q){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(f(ss[b]-ss[a-1], b-a+1) == f(tt[d]-tt[c-1], d-c+1)) YES;
    else NO;
  }

  return 0;
}