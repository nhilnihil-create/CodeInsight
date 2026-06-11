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
  cin >> N;
  vector<ll> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    a[i]--;
  }
  ll ans = 0;
  set<ll> visited;
  for (int i = 0; i < N; i++) {
    if (visited.count(i)) continue;
    if (i == a[a[i]]) {
      ans++;
      visited.insert(i);
      visited.insert(a[i]);
    }
  }
  cout << ans << endl;
  return 0;
}