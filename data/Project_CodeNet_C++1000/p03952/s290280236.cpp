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
  int N, x;
  cin >> N >> x;
  int sz = N*2-1;
  if (N == 2 && x == 2) {
    cout << "Yes" << endl;
    rep(i, sz)
      cout << i+1 << endl;
    return 0;
  }
  if (x <= 1 || x >= sz) {
    cout << "No" << endl;
    return 0;
  }
  vector<int> ans(sz);
  if (x > 2) {
    ans[sz/2] = x;
    ans[sz/2-1] = x-1;
    ans[sz/2+1] = x+1;
    ans[sz/2+2] = x-2;
    int num = 1;
    rep(i, sz) {
      while(num >= x-2 && num <= x+1)
        num++;
      if (!ans[i]) {
        ans[i] = num;
        num++;
      }
    }
  } else {
    ans[sz/2] = x;
    ans[sz/2-1] = x+1;
    ans[sz/2+1] = x-1;
    ans[sz/2+2] = x+2;
    int num = 1;
    rep(i, sz) {
      while(num >= x-1 && num <= x+2)
        num++;
      if (!ans[i]) {
        ans[i] = num;
        num++;
      }
    }
  }
  cout << "Yes" << endl;
  rep(i, sz) cout << ans[i] << endl;
  return 0;
}