#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
using vi = vector<int>; // intの1次元の型に vi という別名をつける
using vvi = vector<vi>; // intの2次元の型に vvi という別名をつける
using vl = vector<ll>;  // long longの1次元の型に vl という別名をつける
using vvl = vector<vl>; // long longの2次元の型に vvl という別名をつける
int MOD = 1000000007; //10^9 + 7

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// 無限大の値
const ll  lINF = 1LL << 60;
const int iINF = 1 << 29;

int main(void){
  int n;
  cin >> n;
  vi t(n);
  rep(i,n) cin >> t[i];

  int m;
  cin >> m;

  vi p(m),x(m);
  rep(i,m) cin >> p[i] >> x[i];
  rep(i,m){
    int ans = 0;
    
    rep(j,n){
      if(p[i]-1==j) ans += x[i];
      else ans += t[j];
    }
    cout << ans << endl;
  }

  return 0;
} 