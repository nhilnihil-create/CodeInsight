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
#include <numeric>

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


signed main() {
  int N, x; 
  cin >> N >> x;

  if(x == 1 || x == 2*N-1){
    No; return 0;
  }

  Yes;

  if(N == 2){
    cout << "1 2 3" << endl;
    return 0;
  }
  
  vector<bool> used(N*2+10, false);
  vector<int> ans(N*2-1, 0);
  if(x != 2){
    ans[N-2] = x-1;
    ans[N-1] = x;
    ans[N+0] = x+1;
    ans[N+1] = x-2;
    REP(i, 4) used[x-2+i] = true;
  }else{
    ans[N-2] = 3;
    ans[N-1] = 2;
    ans[N+0] = 1;
    ans[N+1] = 4;
    REP(i, 4) used[i+1] = true;
  }

  int now = 1;
  REP(i, N-2){
    while(used[now]) now++;
    ans[i] = now;
    used[now++] = true;
  }
  FOR(i, N+2, 2*N-1){
    while(used[now]) now++;
    ans[i] = now;
    used[now++] = true;
  }

  REP(i, 2*N-1) cout << ans[i] << endl;

  return 0;
}