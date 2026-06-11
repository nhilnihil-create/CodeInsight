#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
  long long Q, H, S, D, N;
  cin >> Q >> H >> S >> D >> N;

  // 0.25, 0.5, 1, 2

  long long cost = 0;

  if (D < 2 * S && D < 4 * H && D < 8 * Q) {
    cost += (N / 2) * D;
    N = N - floor(N / 2) * 2;
  }

  long long case1 = N * S;
  long long case2 = 2 * N * H;
  long long case3 = 4 * N * Q;

  cost += min(min(case1, case2), case3);

  cout << cost << endl;

  return 0;
}