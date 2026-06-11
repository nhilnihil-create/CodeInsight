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
  ll N, x;
  cin >> N >> x;
  vector<int> a(N);
  ll ans = 0;
  rep(i, N) {
    cin >> a[i];
    ans += a[i];
  }
  for (int i=1; i<N; i++) {
    int tmp = a[N-1];
    for (int j=N-1; j>0; j--)
      chmin(a[j], a[j-1]);
    chmin(a[0], tmp);
    ll sum = 0;
    rep(j, N) sum += a[j];
    chmin(ans, sum+i*x);
  }
  cout << ans << endl;
  return 0;
}