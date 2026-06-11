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
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  int mn = 1e9, mx = 0;
  rep(i, n) {
    chmin(mn, a[i]);
    chmax(mx, a[i]);
  }
  if (mx-mn > 1) {
    cout << "No" << endl;
    return 0;
  }
  if (mx == mn) {
    if (mx <= n/2 || mx == n-1)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  } else {
    int num1 = 0, num2 = 0;
    rep (i, n) {
      if (a[i] == mn)
        num1++;
      else
        num2++;
    }
    if (mn >= num1 && mx <= num1+num2/2 && num2 >= 2)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}