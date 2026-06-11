#include <iostream>
using namespace std;

int main(void) {
  int64_t N, A, B;
  cin >> N >> A >> B;

  int64_t answer;
  if (A > B) {
    answer = 0;
  } else if (N == 1) {
    answer = (A == B) ? 1 : 0;
  } else {
    N -= 2;
    answer = (B * N) - (A * N) + 1;
  }
  cout << answer << endl;
  return 0;
}