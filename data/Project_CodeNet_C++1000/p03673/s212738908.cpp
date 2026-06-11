#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using P = pair<int,int>;
using ll = long long;
const ll INF = 1LL<<60;
const double PI = 3.1415926535897932;
const int MOD = 1e9 + 7;

//cin.tie(0);ios::sync_with_stdio(false);
int main() {
  int n;
  cin >> n;
  vector<int> head;
  vector<int> tail;

  rep (i, n) {
    int a;
    cin >> a;
    
    if (i % 2 == 0 && i != 0) {
      head.push_back(a);
    } else {
      tail.push_back(a);
    }
  }

  vector<int> ans;

  if (n % 2 != 0) {
    reverse(head.begin(), head.end());
    for (auto v : head) ans.push_back(v);
    for (auto v : tail) ans.push_back(v);
  } else {
    reverse(tail.begin(), tail.end());
    for (auto v : tail) ans.push_back(v);
    for (auto v : head) ans.push_back(v);
  }

  for (auto v : ans) {
    cout << v << " ";
  }
  cout << endl;
  return 0;
}
