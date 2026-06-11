#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <deque>
#include <stack>
#include <iomanip>
#include <cmath>


using namespace std;


typedef long long ll;
typedef long double ld;


const int MAXNUM = 200002;
const ll MOD = 1000000007ll;


int H, W, A, B;
ll fac[MAXNUM];


void input() {
  cin >> H >> W >> A >> B;
}


void preprocess() {
  fac[0] = 1;
  for (int i = 1 ; i < MAXNUM ; i++) {
    fac[i] = (fac[i-1] * i) % MOD;
  }
}


ll factorial(int x) {
  return fac[x];
}


ll getPow(ll b, ll e) {
  //cerr << "B = " << b << ", E = " << e << "\n";
  if (e == 0) return 1;
  if (e == 1) return b;
  if (e % 2 == 0) {
    ll tmp = getPow(b, e / 2);
//  cerr << " Ret B = " << b << ", E = " << e << "\n";
    return (tmp * tmp) % MOD;
  } else {
//  cerr << " Ret B = " << b << ", E = " << e << "\n";
    return (b * getPow(b, e - 1)) % MOD;
  }
}


ll getInverse(int x) {
  if (x == 1) {
    return 1;
  }
  return getPow(x, MOD - 2);
}


ll NCR(int n, int k) {
  ll num = factorial(n);
  ll den = (factorial(k) * factorial(n-k)) % MOD;
  //cerr << "LUL\n";
  ll ret =  (num * getInverse(den)) % MOD;
  //cerr << "RET = " << ret << "\n";
  return ret;
}


ll getWays(int fr, int fc, int tr, int tc) {
  int dr = tr - fr;
  int dc = tc - fc;
  //cerr << "DR = " << dr << ", DC = " << dc << "\n";
  return NCR(dr + dc, dr);
}


void solve() {
  ll ans = 0;
  for (int r = 0 ; r < H-A ; r++) {
    //cerr << "R = " << r << "\n";
    ans = (ans + getWays(0, 0, r, B-1) * getWays(r, B, H-1, W-1)) % MOD;
  }
  cout << ans;
}






int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);

  int T;
//  cin >> T;
  T = 1;

  for (int i = 0 ; i < T ; i++) {
    input();
    preprocess();
    solve();
  }

  return 0;
}
