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
  int N;
  cin >> N;
  vector<int> a(N*3);
  rep(i, N*3) cin >> a[i];
  priority_queue<int, vector<int>, greater<int>> mx;
  ll mxsum = 0;
  rep(i, N) {
    mx.push(a[i]);
    mxsum += a[i];
  }
  vector<ll> l(N+1);
  l[0] = mxsum;
  rep(i, N) {
    if (a[N+i] > mx.top()) {
      mxsum += a[N+i]-mx.top();
      mx.pop();
      mx.push(a[N+i]);
    }
    l[i+1] = mxsum;
  }
  priority_queue<int> mn;
  ll mnsum = 0;
  rep(i, N) {
    mn.push(a[N*2+i]);
    mnsum += a[N*2+i];
  }
  vector<ll> r(N+1);
  r[N] = mnsum;
  for (int i=N-1; i>=0; i--) {
    if (a[N+i] < mn.top()) {
      mnsum += a[N+i]-mn.top();
      mn.pop();
      mn.push(a[N+i]);
    }
    r[i] = mnsum;
  }
  ll ans = -1e18;
  rep(i, N+1)
    chmax(ans, l[i]-r[i]);
  cout << ans << endl;
  return 0;
}