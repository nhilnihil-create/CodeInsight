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
  vector<int> a(n), s;
  rep(i, n) cin >> a[i];
  s = a;
  sort(s.begin(), s.end());
  multiset<int> st;
  for (int i = 0; i < n; i+=2)
    st.insert(s[i]);
  int ans = 0;
  for (int i = 0; i < n; i+=2) {
    if (st.find(a[i]) == st.end())
      ans++;
  }
  cout << ans << endl;
  return 0;
}