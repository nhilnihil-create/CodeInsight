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
  map<ll, ll> m;
  set<ll> s;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    m[a[i]]++;
    s.insert(a[i]);
  }
  ll ans = 0;
  for (auto i : s) {
    ans = max(ans, m[i - 1] + m[i] + m[i + 1]);
  }
  cout << ans << endl;
  return 0;
}