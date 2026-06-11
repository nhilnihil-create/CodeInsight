#include <algorithm>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  vector<int64_t> SIZE(4);
  int64_t N;
  cin >> SIZE[0] >> SIZE[1] >> SIZE[2] >> SIZE[3] >> N;

  int64_t answer = 0;
  vector<int64_t> QHSD(4);
  int times = 8;
  for (int j = 0; j < 4; ++j) {
    QHSD[j] = SIZE[j] * times;
    times /= 2;
  }
  sort(QHSD.begin(), QHSD.end());
  answer += QHSD[0] * (N / 2);
  if (N % 2 == 0) {
    cout << answer << endl;
    return 0;
  }

  vector<int64_t> QHS(3);
  times = 4;
  for (int j = 0; j < 3; ++j) {
    QHS[j] = SIZE[j] * times;
    times /= 2;
  }
  sort(QHS.begin(), QHS.end());
  answer += QHS[0];
  cout << answer << endl;
  return 0;
}
