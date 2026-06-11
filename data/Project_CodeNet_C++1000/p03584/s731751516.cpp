#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int N;
  ll K;
  cin >> N >> K;
  vector<ll> A(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }
  vector<ll> masks;
  for (ll m = K; m > 0; m &= m - 1) {
    masks.push_back(m - 1);
  }
  masks.push_back(K);
  ll res = 0;
  for (ll m : masks) {
    ll sum = 0;
    for (int i = 0; i < N; i++) {
      if ((A[i] & m) == A[i]) {
        sum += B[i];
      }
    }
    res = max(res, sum);
  }
  cout << res << endl;
  return 0;
}
