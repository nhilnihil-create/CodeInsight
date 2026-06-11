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
  int N; cin >> N;
  vector<LL> A(N), B(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i] >> B[i];
  }

  LL cnt = 0;
  for (int i = N-1; i >= 0; --i) {
    if ((A[i] + cnt) % B[i] == 0) continue;
    LL x = B[i] - (A[i] + cnt) % B[i];
    cnt += x;
  }
  cout << cnt << endl;
}
