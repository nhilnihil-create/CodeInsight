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
ll memo[51][2];

int main() {
  ll N, P;
  cin >> N >> P;
  vector<ll> A(N);
  vector<ll> cnt(2, 0);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    cnt[A[i] % 2]++;
  }
  if (cnt[0] == N) {
    if (P == 0) {
      cout << (1LL << N) << endl;
    } else {
      cout << 0 << endl;
    }
    return 0;
  }
  cout << (1LL << (N - 1)) << endl;
  return 0;
}