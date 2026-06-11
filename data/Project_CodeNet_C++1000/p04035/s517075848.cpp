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
  int n, l;
  cin >> n >> l;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  rep(i, n-1) {
    if (a[i]+a[i+1] >= l) {
      cout << "Possible" << endl;
      rep(j, i)
        cout << j+1 << endl;
      for (int j = n-2; j >= i; j--)
        cout << j+1 << endl;
      return 0;
    }
  }
  cout << "Impossible" << endl;
  return 0;
}