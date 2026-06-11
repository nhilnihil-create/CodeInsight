#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int64_t N, A, B, C, D;
  cin >> N >> A >> B >> C >> D;
  int64_t Y = B - A;
  rep(i, N + 1) {
    int64_t minY = C * (N - 1 - i) - D * i;
    int64_t maxY = -C * i + D * (N - 1 - i);
    if (minY <= Y && Y <= maxY) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}