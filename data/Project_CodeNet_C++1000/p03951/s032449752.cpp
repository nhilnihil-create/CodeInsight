#include <iostream>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  string s, t;
  cin >> s >> t;

  for (int i = 0; i < N; ++i) {
    if (s.substr(i, N - i) == t.substr(0, N - i)) {
      cout << N + i << endl;
      return 0;
    }
  }
  cout << 2 * N << endl;
  return 0;
}