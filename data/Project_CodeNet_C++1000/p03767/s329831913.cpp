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
  vector<ll> a(3 * N);
  for (int i = 0; i < 3 * N; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  deque<ll> q;
  for (int i = 0; i < a.size(); i++) {
    q.push_back(a[i]);
  }
  ll ans = 0;
  while (!q.empty()) {
    q.pop_front();
    q.pop_back();
    ans += q.back();
    q.pop_back();
  }
  cout << ans << endl;
  return 0;
}