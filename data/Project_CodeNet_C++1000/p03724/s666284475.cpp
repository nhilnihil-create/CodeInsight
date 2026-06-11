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
  ll N, M;
  cin >> N >> M;
  ll a, b;
  map<ll, ll> m;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    m[a]++;
    m[b]++;
  }
  bool succ = true;
  for (auto p : m) {
    if (p.second % 2 == 1) succ = false;
  }
  if (succ) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}