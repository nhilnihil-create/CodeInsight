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
  vector<ll> A(N), accum(N);
  ll sum_a = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (i == 0)
      accum[i] = A[i];
    else
      accum[i] = accum[i] + A[i];
  }
  sort(A.begin(), A.end());
  accum[0] = A[0];
  for (int i = 1; i < N; i++) {
    accum[i] = accum[i - 1] + A[i];
  }
  ll ans = 1;
  for (int i = N - 2; i >= 0; i--) {
    if (A[i + 1] <= 2 * accum[i]) {
      ans++;
    } else {
      break;
    }
  }
  cout << ans << endl;
  return 0;
}