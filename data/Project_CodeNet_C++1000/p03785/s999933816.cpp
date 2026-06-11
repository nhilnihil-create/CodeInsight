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
  ll N, C, K;
  cin >> N >> C >> K;
  vector<ll> t(N);
  for (int i = 0; i < N; i++) {
    cin >> t[i];
  }
  sort(t.begin(), t.end());
  ll ans = 1;
  ll end = t[0] + K;
  ll cnt = 1;
  for (int i = 1; i < N; i++) {
    if (t[i] <= end && cnt < C) {
      cnt++;
      continue;
    }
    ans++;
    cnt = 1;
    end = t[i] + K;
  }
  cout << ans << endl;
  return 0;
}