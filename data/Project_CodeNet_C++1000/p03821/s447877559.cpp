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
  vector<ll> A(N), B(N);
  vector<ll> C(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }
  ll ans = 0;
  ll accum = 0;
  for (int i = N - 1; i >= 0; i--) {
    if ((A[i] + accum) % B[i] != 0) {
      ll new_cnt = (B[i] - (A[i] + accum) % B[i]);
      ans += new_cnt;
      accum += new_cnt;
    }
  }
  cout << ans << endl;
  return 0;
}