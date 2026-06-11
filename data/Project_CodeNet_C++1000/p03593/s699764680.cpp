#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
using namespace std;

using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void dump(vector<T> v) { for (auto& x : v) cerr << x << " "; cerr << endl; }
template<class T> inline void dump(vector<pair<T, T>> v) { for (auto& p : v) cerr << p.first << " " << p.second << endl; }
template<class T> inline void dump(vector<vector<T>> vv) { for (auto& v : vv) {for (auto& x : v) cerr << x << " "; cerr << endl;} }

constexpr int INF = 1e9+5;
constexpr long long INFLL = 1LL<<60;
constexpr double eps = (1e-9);

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  rep(i, h) cin >> a[i];

  map<char, int> mp;
  rep(i, h) rep(j, w) {
    mp[a[i][j]]++;
  }

  int num4 = 0;
  int num2 = 0;
  int num1 = 0;

  for (auto& p : mp) {
    int num = p.second;
    num4 += num / 4;  num %= 4;
    num2 += num / 2; num %= 2;
    num1 += num;
  }

  int req4 = 0;
  int req2 = 0;
  int req1 = 0;

  if (h % 2 == 0) {
    req4 = (w / 2) * (h / 2);
    req2 = (w % 2) * (h / 2);
  } else {
    if (w % 2 == 0) {
      req4 = (w / 2) * (h / 2);
      req2 = w / 2;
    } else {
      req4 = (w / 2) * (h / 2);
      req2 = (w / 2) + (h / 2);
      req1 = 1;
    }
  }

//  cerr << req4 << " " << req2 << " " << req1 << endl;
//  cerr << num4 << " " << num2 << " " << num1 << endl;

  if (num4 < req4) {
    puts("No");
    return 0;
  }
  num4 -= req4;
  if (num4 > 0) num2 += num4 * 2;
  if (num2 < req2) {
    puts("No");
    return 0;
  }

  puts("Yes");

  return 0;
}
