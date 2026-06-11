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


signed main() {
  int N, x;
  cin >> N >> x;

  if(x == 1 || x == 2*N-1){
    No;
    return 0;
  }
  if(N == 2){
    if(x == 1) No;
    else{
      Yes;
      cout << 1 << endl;
      cout << 2 << endl;
      cout << 3 << endl;
    }
    return 0;
  }

  vector<int> ans(2*N-1, 0);
  vector<bool> used(2*N, false);
  if(x == 2){
    ans[N-2+0] = 4;
    ans[N-2+1] = 2;
    ans[N-2+2] = 1;
    ans[N-2+3] = 3;

    used[1] = true;  used[2] = true;  used[3] = true;  used[4] = true;
  }else{
    ans[N-2+0] = x-1;
    ans[N-2+1] = x+0;
    ans[N-2+2] = x+1;
    ans[N-2+3] = x-2;

    used[x-2] = true;  used[x-1] = true;  used[x+0] = true;  used[x+1] = true;
  }
  
  int c = 1;
  REP(i, N*2-1){
    if(ans[i]) continue;
    while(used[c]) c++;
    ans[i] = c++;
  }

  Yes;
  REP(i, N*2-1) cout << ans[i] << endl;

  return 0;
}