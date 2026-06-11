#include <cassert>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <limits.h>
#include <map>
#include <queue>
#include <set>
#include <string.h>
#include <vector>

using namespace std;
typedef long long ll;

int N, K;
vector<int> A;

bool f(int x) {
  if (A[x] >= K) return true;

  bool sum[K + 1];
  memset(sum, false, sizeof(sum));
  sum[0] = true;
  int d;

  for (int i = 1; i <= N; ++i) {
    if (i == x) continue;
    int a = A[i];

    for (int k = K; k >= 0; --k) {
      if (!sum[k]) continue;

      int d = min(K, k + a);

      sum[d] = true;
    }
  }

  for (int i = K - A[x]; i < K; ++i) {
    if (sum[i]) return true;
  }

  return false;
}

int main() {
  cin >> N >> K;

  A.push_back(0);
  int a;
  for (int i = 0; i < N; ++i) {
    cin >> a;
    A.push_back(a);
  }

  sort(A.begin(), A.end());

  A.push_back(K);

  int ok = N + 1;
  int ng = 0;

  while (abs(ok - ng) > 1) {
    int x = (ok + ng) / 2;

    bool res = f(x);

    if (f(x)) {
      ok = x;
    } else {
      ng = x;
    }
  }

  cout << ng << endl;

  return 0;
}
