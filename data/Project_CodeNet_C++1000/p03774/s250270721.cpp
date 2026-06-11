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
  int n,m;
  cin >> n >> m;

  vi a(n), b(n), c(m), d(m);
  rep(i,n) cin >> a[i] >> b[i];
  rep(i,m) cin >> c[i] >> d[i];
  
  vi min_d(n,MOD),ans(n,51);

  rep(i,n){
    rep(j,m){
      int dis = (abs(c[j]-a[i]) + abs(d[j]-b[i]));
      if(dis<min_d[i]){
        min_d[i] = dis;
        ans[i] = j+1;
      }
    }
  }

  rep(i,n)cout << ans[i] << endl;
  return 0;
} 