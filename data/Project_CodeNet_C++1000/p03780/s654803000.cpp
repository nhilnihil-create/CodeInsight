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
#include <cstring>
#include <cmath>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  a.push_back(0);
  a.push_back(1e9+1);
  sort(a.begin(), a.end());
  int l = 0, r = n+1;
  while (r-l > 1) {
    int mid = (l+r)/2;
    vector<bool> dp(k);
    dp[0] = true;
    int mx = 0;
    rep(i, n+2) {
      if (i == mid)
        continue;
      for (int j = k-1; j >=0; j--) {
        if (dp[j] && j+a[i] < k) {
          dp[j+a[i]] = true;
          chmax (mx, j+a[i]);
        }
      }
    }
    if (mx+a[mid] >= k)
      r = mid;
    else
      l = mid;
  }
  cout << l << endl;
  return 0;
}