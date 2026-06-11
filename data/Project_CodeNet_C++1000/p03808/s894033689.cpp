#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
using namespace std;
constexpr int kMod = 1000000007;
typedef long long LL;

int main() {
  LL N; cin >> N;
  LL sum = 0;
  vector<LL> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    sum += A[i];
  }

  LL num = (N * (N + 1LL)) / 2;
  if (sum % num) {
    cout << "NO" << endl;
    return 0;
  }

  LL k = sum / num;

  for (int i = 0; i < N; ++i) {
    LL d = A[(i + 1) % N] - A[i] - k;
    if (d > 0 || (-d) % N) {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
  return 0;
}
