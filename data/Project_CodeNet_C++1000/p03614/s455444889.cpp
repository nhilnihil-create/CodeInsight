#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int runlength = 0;
  int res = 0;
  for (int i = 1; i <= N; i++) {
    int p;
    cin >> p;
    if (p == i) {
      ++runlength;
    } else {
      res += (runlength + 1) / 2;
      runlength = 0;
    }
  }
  res += (runlength + 1) / 2;
  cout << res << endl;
  return 0;
}
