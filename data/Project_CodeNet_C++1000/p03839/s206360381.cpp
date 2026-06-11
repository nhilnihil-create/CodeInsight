#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> a(N);
  rep(i, N) cin >> a[i];
  vector<ll> sum(N+1), psum(N+1);
  rep(i, N) {
    sum[i+1] = sum[i]+a[i];
    psum[i+1] = psum[i]+(a[i]>0?a[i]:0);
  }
  ll ans = 0;
  rep(i, N-K+1) {
    ll s = sum[i+K]-sum[i];
    ll l = psum[i];
    ll r = psum[N]-psum[i+K];
    chmax(ans, max(s+l+r, l+r));
  }
  cout << ans << endl;
  return 0;
}