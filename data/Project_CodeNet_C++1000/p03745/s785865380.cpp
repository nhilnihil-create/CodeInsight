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
  vector<ll> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  if (N == 1) {
    cout << 1 << endl;
    return 0;
  }
  ll ans = 1;
  int state = 0;
  for (int i = 0; i < N - 1; i++) {
    if (A[i] < A[i + 1]) {
      if (state == -1) {
        ans++;
        state = 0;
      } else {
        state = 1;
      }
    }
    if (A[i] > A[i + 1]) {
      if (state == 1) {
        ans++;
        state = 0;
      } else {
        state = -1;
      }
    }
  }
  cout << ans << endl;
  return 0;
}