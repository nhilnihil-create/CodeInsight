#include <algorithm>
#include <cstring>
#include <deque>
#include <functional>
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
  ll L, T;
  while (cin >> N >> L >> T) {
    vector<ll> X(N), W(N);
    for (int i = 0; i < N; i++) {
      cin >> X[i] >> W[i];
    }
    ll cross0 = 0;
    for (int i = 1; i < N; i++) {
      if (W[0] != W[i]) {
        ll d = W[0] == 1 ? X[i] - X[0] : L - (X[i] - X[0]);
        if (d <= 2 * T) {
          ll rem = 2 * T - d;
          ll tmp = rem / L + 1;
          if (W[0] == 1 && rem % L == 0) {
            --tmp;
          }
          cross0 += tmp;
        }
      }
    }
    int label0 = W[0] == 1 ? cross0 % N : (N - cross0 % N) % N;
    vector<ll> pos(N);
    for (int i = 0; i < N; i++) {
      pos[i] = W[i] == 1 ? (X[i] + T) % L : (X[i] - T % L + L) % L;
    }
    ll pos0 = pos[0];
    sort(pos.begin(), pos.end());
    int off = find(pos.begin(), pos.end(), pos0) - pos.begin();
    vector<ll> ans(N);
    for (int i = 0; i < N; i++) {
      int j = (off + i) % N;
      int label = (label0 + i) % N;
      ans[label] = pos[j];
    }
    for (ll x : ans) {
      cout << x << endl;
    }
  }
  return 0;
}
