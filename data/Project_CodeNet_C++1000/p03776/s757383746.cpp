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

vector<vector<int>> C;

void comb_init(int N){
  C = vector<vector<int>>(N+1, vector<int>(N+1));
  REP(i, N+1) REP(j, i+1){
    if(j == 0 || j == i) C[i][j] = 1;
    else C[i][j] = C[i-1][j-1]+C[i-1][j];
  }
}

int comb(int n, int r){
  return C[n][r];
}

signed main() {
  int N, A, B; 
  cin >> N >> A >> B;

  int M = A;

  map<int, int> m;
  REP(i, N){
    int v;
    cin >>  v;
    m[v]++;
  }

  vector<pair<int, int>> v;
  for(auto p : m) v.emplace_back(p);
  reverse(ALL(v));

  comb_init(51);

  int sum = 0;
  int ans = 1;
  bool flag = true;
  for(auto p : v){
    if(p.second < A){
      A -= p.second; B -= p.second;
      sum += p.first*p.second;
      flag = false;
    }else{
      ans = 0;
      if(flag){
        for(int i = A; i <= min(p.second, B); i++){
          ans += comb(p.second, i);
        }
      }else{
        ans = comb(p.second, A);
      }
      sum += p.first*A;
      break;
    }
  }

  cout << (double)sum/M << "\n";
  cout << ans << "\n";

  return 0;
}