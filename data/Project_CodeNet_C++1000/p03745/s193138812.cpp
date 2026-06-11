#include <iostream>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  int mode = 0;  // 0: not determin, 1: ascending, 2: descending
  int answer = 1;
  int P;
  cin >> P;
  for (int i = 1; i < N; ++i) {
    int C;
    cin >> C;
    if (mode == 0) {
      if (P < C)
        mode = 1;
      else if (P > C)
        mode = 2;
    } else if (mode == 1) {
      if (P > C) {
        answer++;
        mode = 0;
      }
    } else {
      if (P < C) {
        answer++;
        mode = 0;
      }
    }
    P = C;
  }
  cout << answer << endl;
  return 0;
}