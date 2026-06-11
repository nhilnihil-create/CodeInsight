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
  ll N;
  map<int, int> m;
  cin >> N;
  ll x;
  for (int i = 0; i < N; i++) {
    cin >> x;
    m[x % 2]++;
  }
  string ans = (m[1] % 2 == 0) ? "YES" : "NO";
  cout << ans << endl;
  return 0;
}