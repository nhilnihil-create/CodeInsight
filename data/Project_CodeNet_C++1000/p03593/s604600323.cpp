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
struct INIT { INIT(){
  cin.tie(0); ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
}}INIT;


signed main() {
  int H, W; 
  cin >> H >> W;

  map<char, int> m;
  REP(i, H){
    string s;
    cin >> s;
    REP(j, s.size()){
      m[s[j]]++;
    }
  }

  vector<int> cnt(3, 0);
  for(auto p : m){
    while(p.second >= 4){
      p.second -= 4;
      cnt[2]++;
    }
    while(p.second >= 2){
      p.second -= 2;
      cnt[1]++;
    }
    while(p.second >= 1){
      p.second -= 1;
      cnt[0]++;
    }
  }

  vector<int> req(3, 0);
  if(H%2 == 0 && W%2 == 0){
    req[2] = H*W/4;
  }else if(H%2 == 1 && W%2 == 1){
    req[2] = (H*W-W/2*2-H/2*2-1)/4;
    req[1] = W/2+H/2;
    req[0] = 1;
  }else if(H%2 == 1){
    req[2] = (H*W-W/2*2)/4;
    req[1] = W/2;
  }else{
    req[2] = (H*W-H/2*2)/4;
    req[1] = H/2;
  }

  bool ans = true;
  RREP(i, 3){
    if(req[i] > cnt[i]) ans = false;
    if(i != 0){
      cnt[i-1] += (cnt[i]-req[i])*2;
    }
  }

  ans? Yes: No;

  return 0;
}