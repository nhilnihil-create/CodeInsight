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


signed main() {
  int N, M;
  cin >> N >> M;

  vector<int> A(N);
  REP(i, N) cin >> A[i];

  map<int, int> m;
  REP(i, N) m[A[i]]++;

  vector<int> cnt(M);
  vector<vector<int>> num(M);
  for(auto p : m){
    cnt[p.first%M] += p.second;
    num[p.first%M].emplace_back(p.second);
  }

  int ans = cnt[0]/2;
  FOR(i, 1, M){
    int j = M-i;
    if(j < i) break;
    if(i == j) ans += cnt[i]/2;
    else{
      int MIN = min(cnt[i], cnt[j]);
      ans += MIN;
      cnt[i] -= MIN; cnt[j] -= MIN;

      REP(k, num[i].size()){
        while(num[i][k] >= 2 && cnt[i] >= 2){
          ans++; num[i][k] -= 2; cnt[i] -= 2;
        }
      }
      REP(k, num[j].size()){
        while(num[j][k] >= 2 && cnt[j] >= 2){
          ans++; num[j][k] -= 2; cnt[j] -= 2;
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}