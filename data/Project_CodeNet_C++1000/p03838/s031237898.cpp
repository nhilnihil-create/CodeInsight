#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
#define rep(i, n) for(int i=0;i<(int)(n);++i)
template <typename T> ll gcd(T a, T b) {return b?gcd(b, a%b):a;}
template <typename T> ll lcm(T a, T b) {return a * b / gcd(a, b);};
template <typename T> inline void chmin(T &a, const T& b){if(a>b)a=b;}
template <typename T> inline void chmax(T &a, const T& b){if(a<b)a=b;}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long x[2], y[2];
  cin >> x[0] >> y[0];
  x[1] = -x[0], y[1] = -y[0];
  long long ans = LLONG_MAX - 100;
  
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      ll tmp = y[j] - x[i];
      if (i == 1) ++tmp;
      if (j == 1) ++tmp;
      if (x[i] <= y[j]) {
        chmin(ans, tmp);
      }
    }
  }
  cout << ans << '\n';
}
