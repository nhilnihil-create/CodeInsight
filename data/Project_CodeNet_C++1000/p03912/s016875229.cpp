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
  int N, M; 
  cin >> N >> M;

  vector<int> cnt(M, 0);
  vector<int> vec(M, 0);

  vector<int> A(N);
  map<int, int> m;
  REP(i, N){
    cin >> A[i];
    m[A[i]]++;
    cnt[A[i]%M]++;
  }

  for(auto p : m){
    vec[p.first%M] += p.second/2;
  }

  int ans = cnt[0]/2;
  FOR(i, 1, M){
    int j = M-i;

    if(i == j){
      ans += cnt[i]/2;
      cnt[i] %= 2;
    }
    else{
      int now = min(cnt[i], cnt[j]);
      ans += now;
      cnt[i] -= now;
      cnt[j] -= now;
    }

    ans += min(cnt[i]/2, vec[i]);
  }

  cout << ans << "\n";

  return 0;
}