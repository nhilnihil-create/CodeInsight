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

int N;
int solve(vector<int> A){
  int ret = 0;
  int sum = 0;
  REP(i, N-1) A[i+1] += A[i];
  FOR(i, 1, N){
    A[i] += sum;
    if(A[i]*A[i-1] >= 0){
      if(A[i] == 0){
        if(A[i-1] < 0){
          sum++;
          ret++;
          A[i] += 1;
        }else{
          sum--;
          ret++;
          A[i] -= 1;
        }
      }else if(A[i] > 0){
        sum -= A[i]+1;
        ret += A[i]+1;
        A[i] = -1;
      }else{
        sum += -A[i]+1;
        ret += -A[i]+1;
        A[i] = 1;
      }
    }
  }
  return ret;
}

signed main() {
  cin >> N;

  vector<int> A(N);
  REP(i, N) cin >> A[i];

  int ans = 0;
  if(A[0] != 0){
    ans = solve(A);
    int ret = abs(A[0])+1;
    if(A[0] > 0){
      A[0] = -1;
    }else{
      A[0] = 1;
    }
    chmin(ans, solve(A)+ret);
  }
  else{
    A[0] = 1;
    ans = solve(A)+1;
    A[0] = -1;
    chmin(ans, solve(A)+1);
  }

  cout << ans << endl;

  return 0;
}