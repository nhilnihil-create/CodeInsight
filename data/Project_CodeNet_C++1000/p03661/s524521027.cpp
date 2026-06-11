#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 1ll << 62;

int main() {
  int N;
  cin >> N;
  vector<ll> a(N);
  ll sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    sum += a[i];
  }
  ll res = INF;
  ll x = 0;
  for (int i = 0; i < N - 1; i++) {
    x += a[i];
    ll y = sum - x; 
    res = min(res, abs(x - y));
  }
  cout << res << endl;
  return 0;
}
