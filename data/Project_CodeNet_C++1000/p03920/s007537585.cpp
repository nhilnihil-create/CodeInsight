#include <iostream>

using namespace std;

int main()
{
  int N; cin >> N;

  int X = 0, idx = 0;
  for (int i = 1; i <= N; i++) {
    X += i;
    if (X >= N) {
      idx = i;
      break;
    }
  }

  int d = X - N;
  for (int i = 1; i <= idx; i++) {
    if (i != d) cout << i << endl;
  }

  return 0;
}