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

#define SPBR(w, n) std::cout<<(w + 1 == n ? '\n' : ' ');
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define ALL(i) (i).begin(), (i).end()
#define FOR(i, a, n) for(int i=(a);i<(n);++i)
#define RFOR(i, a, n) for(int i=(n)-1;i>=(a);--i)
#define REP(i, n) for(int i=0;i<int(n);++i)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define IN(a, x, b) (a<=x && x<b)
#define OUT(a, x, b) (x<a || b<=x)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

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


signed main() {
  int W, H; 
  cin >> W >> H;

  int A;
  priority_queue<int, vector<int>, greater<int>> p, q;
  REP(i, W){
    cin >> A;
    p.push(A);
  }
  REP(i, H){
    cin >> A;
    q.push(A);
  }

  int ans = 0;
  int cp = H+1, cq = W+1;
  while(!p.empty() && !q.empty()){
    int np = p.top();
    int nq = q.top();
    if(np <= nq){
      ans += cp*np;
      cq--; p.pop();
    }else{
      ans += cq*nq;
      cp--; q.pop();
    }
  }
  while(!p.empty()){
    ans += p.top(); p.pop();
  }
  while(!q.empty()){
    ans += q.top(); q.pop();
  }

  cout << ans << "\n";

  return 0;
}