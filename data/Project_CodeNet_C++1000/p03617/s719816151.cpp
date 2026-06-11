#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;

int main() {
  ll Q, H, S, D, N, ans;
  cin >> Q >> H >> S >> D >> N;
  ll P = min({4 * Q, 2 * H, S});
  if (2 * P <= D) {
    ans = N * P;
  } else {
    ans = N / 2 * D + N % 2 * P;
  }
  cout << ans << endl;
}
