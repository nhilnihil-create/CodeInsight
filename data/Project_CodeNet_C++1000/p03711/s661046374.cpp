#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  ll x, y;
  cin >> x >> y;
  set<ll> g1 = {1, 3, 5, 7, 8, 10, 12};
  set<ll> g2 = {4, 6, 9, 11};
  set<ll> g3 = {2};
  bool in_g1 = (g1.find(x) != g1.end()) && (g1.find(y) != g1.end());
  bool in_g2 = (g2.find(x) != g2.end()) && (g2.find(y) != g2.end());
  bool in_g3 = (g3.find(x) != g3.end()) && (g3.find(y) != g3.end());
  string ans = (in_g1 || in_g2 || in_g3) ? "Yes" : "No";
  cout << ans << endl;
  return 0;
}