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
const int INF = 1e18;

using namespace std;


signed main() {
  int H, W, N;
  cin >> H >> W >> N;

  if(N == 0){
    cout << (H-2)*(W-2) << endl;
    REP(i, 9) cout << 0 << endl;
    return 0;
  }

  int a, b;
  map<pair<int, int>, int> m;
  REP(i, N){
    cin >> a >> b;
    a--; b--;

    if(a-2 >= 0){
      if(b-2 >= 0) m[make_pair(a-2, b-2)]++;
      if(b-1 >= 0) m[make_pair(a-2, b-1)]++;
      m[make_pair(a-2, b)]++;
    }
    if(a-1 >= 0){
      if(b-2 >= 0) m[make_pair(a-1, b-2)]++;
      if(b-1 >= 0) m[make_pair(a-1, b-1)]++;
      m[make_pair(a-1, b)]++;
    }
    if(b-2 >= 0) m[make_pair(a, b-2)]++;
    if(b-1 >= 0) m[make_pair(a, b-1)]++;
    m[make_pair(a, b)]++;
  }

  vector<int> ans(10, 0);
  for(auto i : m){
    auto p = i.first;
    if(p.first <= H-3 && p.second <= W-3){
      ans[i.second]++;
    }
  }

  ans[0] = (H-2)*(W-2);
  FOR(i, 1, 10){
    ans[0] -= ans[i];
  }
  REP(i, 10){
    cout << ans[i] << endl;
  }

  return 0;
}