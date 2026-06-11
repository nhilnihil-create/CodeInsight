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

vector<vector<int>> comb(60, vector<int>(60));

signed main() {
  int N, A, B; 
  cin >> N >> A >> B;
  int AA = A;

  REP(i, N+5){
    REP(j, i+1){
      if(j == 0 || j == i){
        comb[i][j] = 1;
      }else{
        comb[i][j] = comb[i-1][j-1]+comb[i-1][j];
      }
    }
  }

  vector<int> v(N);
  REP(i, N) cin >> v[i];

  sort(ALL(v), greater<int>());

  map<int, int> m;
  REP(i, N) m[v[i]]++;

  int sum = 0;
  map<int, int>::reverse_iterator i = m.rbegin();
  for(; i != m.rend(); i++){
    sum += i->first*min(A, i->second);
    A -= i->second;
    B -= i->second;
    if(A <= 0){
      A += i->second;
      B += i->second;
      int ans = 0;
      if(v[0] == i->first){
        for(int j = A; j <= B; j++){
          ans += comb[i->second][j];
        }
      }else{
        ans = comb[i->second][A];
      }
      printf("%.9f\n", 1.0*sum/AA);
      cout << ans << endl;
      return 0;
    }
  }

  return 0;
}