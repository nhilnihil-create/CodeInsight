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
  int H, W; 
  cin >> H >> W;

  vector<int> cnt(26, 0);
  REP(i, H){
    string s;
    cin >> s;
    REP(j, W) cnt[s[j]-'a']++;
  }

  bool ans = true;


  vector<int> requied(3, 0);
  if(H%2 == 1 && W%2 == 1){
    requied[0] = 1; 
    requied[1] = H/2+W/2;; 
  }else if(W%2 == 1){
    requied[1] = H/2;; 
  }else if(H%2 == 1){
    requied[1] = W/2;; 
  }
  requied[2] = (H*W-requied[0]-requied[1]*2)/4;

  vector<int> used(3, 0);
  REP(i, 26){
    if(cnt[i] == 0) continue;
    while(cnt[i] >= 4){
      cnt[i] -= 4;
      used[2]++;
    }
    while(cnt[i] >= 2){
      cnt[i] -= 2;
      used[1]++;
    }
    while(cnt[i] >= 1){
      cnt[i] -= 1;
      used[0]++;
    }
  }

  REP(i, 3){
    if(requied[i] < used[i]) ans = false;
    else if(i != 2){
      requied[i+1] += (requied[i]-used[i])/2;
    }
  }

  ans? Yes: No;

  return 0;
}