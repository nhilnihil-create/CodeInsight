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
/* const int MOD = 998244353; */
const int INF = 1e18;
const double PI = acos(-1);

using namespace std;

int cnt = 0;
vector<int> A(10010);
vector<vector<int>> ans(110, vector<int>(110));
void update(int i, int j){
  int color = cnt+1;
  A[cnt]--;
  if(A[cnt] == 0) cnt++;
  ans[i][j] = color;
}

signed main() {
  int H, W, N; 
  cin >> H >> W >> N;

  REP(i, N) cin >> A[i];

  REP(i, H){
    if(i%2 == 0) REP(j, W) update(i, j);
    else RREP(j, W) update(i, j);
  }

  REP(i, H){
    REP(j, W){
      cout << ans[i][j]; SPBR(j, W);
    }
  }

  return 0;
}