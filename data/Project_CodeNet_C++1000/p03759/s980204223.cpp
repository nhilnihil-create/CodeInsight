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
  ll a, b, c;
  cin >> a >> b >> c;
  string ans = (b - a == c - b) ? "YES" : "NO";
  cout << ans << endl;
  return 0;
}