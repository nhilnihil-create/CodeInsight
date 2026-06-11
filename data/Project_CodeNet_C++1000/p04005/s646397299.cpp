#include <algorithm>
#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  int64_t A, B, C;
  cin >> A >> B >> C;
  int64_t N = A * B * C;
  int64_t NA = N - 2 * (A / 2) * B * C;
  int64_t NB = N - 2 * A * (B / 2) * C;
  int64_t NC = N - 2 * A * B * (C / 2);
  int64_t answer = std::min({NA, NB, NC});
  cout << answer << endl;
  return 0;
}