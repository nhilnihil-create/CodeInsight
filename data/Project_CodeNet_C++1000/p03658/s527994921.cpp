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
  ll N, K;
  cin >> N >> K;
  vector<ll> l(N);
  for (int i = 0; i < N; i++) {
    cin >> l[i];
  }
  sort(l.rbegin(), l.rend());
  ll ans = 0;
  for (int i = 0; i < K; i++) {
    ans += l[i];
  }
  cout << ans << endl;
  return 0;
}