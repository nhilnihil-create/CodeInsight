/**
 *      purpose : 
 *      author  : 𝒌𝒚𝒐𝒎𝒖𝒌𝒚𝒐𝒎𝒖𝒑𝒖𝒓𝒊𝒏
 *      created : 
**/

#include <iostream>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <complex>
#include <numeric>
#include <bitset>
#include <cassert>
#include <cctype>
#include <functional>
#include <iomanip>
#include <random>
#include <utility>

using namespace std;

using int64 = long long;
#define debug(_) cerr << #_ << ": " << (_) << '\n'
template<typename T> inline void chmin(T &a, T b) { if (a > b) a = b; return; }
template<typename T> inline void chmax(T &a, T b) { if (a < b) a = b; return; }
template<typename T> ostream& operator<<(ostream& os, const vector<T>& vec) { os << '{'; for (size_t i = 0; i < vec.size(); ++i) { os << vec[i]; if (i != vec.size() - 1) os << ','; } os << '}'; return os; }
template<typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p) { return os << '{' << p.first << " " << p.second << '}'; }

int main() {
  //ios_base::sync_with_stdio(false);
  //cin.tie(nullptr);

  int n, a, b; cin >> n >> a >> b;
  vector<int64> v(n);
  map<int64, int> mp;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    ++mp[v[i]];
  }
  sort(v.rbegin(), v.rend());
  int64 pascal[51][51];
  fill(pascal[0], pascal[51], 0LL);
  for (int i = 0; i < 51; ++i) {
    for (int j = 0; j < i + 1; ++j) {
      if (j == 0 || j == i) {
        pascal[i][j] = 1LL;
      } else {
        pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
      }
    }
  }

  double best_mean = 0;
  for (int i = 0; i < a; ++i) {
    best_mean += static_cast<double>(v[i]);
  }
  best_mean /= static_cast<double>(a);

  int64 ans = 0;
  int64 target = v[a - 1];
  int target_cnt = 0;
  for (int i = 0; i < a; ++i) {
    if (v[i] == target) ++target_cnt;
  }

  if (v[0] == v[a - 1]) {
    //cerr << "hi" << '\n';
    int same = 0;
    for (int i = a - 1; i <= b - 1; ++i) {
      if (v[i] == v[a - 1]) ++same;
    }
    //debug(same);
    for (int i = 0; i < same; ++i) {
      ans += pascal[mp[v[0]]][a + i];
    }
  } else {
    ans = pascal[mp[v[a - 1]]][target_cnt];
  }

  printf("%.15f\n", best_mean);
  printf("%lld\n", ans);

  return 0;
}