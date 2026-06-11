#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#define MOD (1000000007l)
#define rep(i, n) for(long i = 0; i < n; i++)

using namespace std;

void solve() {
  long N;
  cin >> N;
  long maxA = 0;
  long memoB;
  rep (i, N) {
    long A, B;
    cin >> A >> B;
    if (A > maxA) {
      maxA = A;
      memoB = B;
    }
  }
  cout << memoB + maxA << endl;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout.precision(12);
  solve();
  return 0;
}
