#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;

  cin >> N >> K;

  int result = 0;
  for (int i = 0; i < N; i++) {
    int x;

    cin >> x;

    int diffKx = K - x;

    if (diffKx < 0) {
      diffKx *= -1;
    }

    if (x < diffKx) {
      result += x * 2;
    } else {
      result += diffKx * 2;
    }
  }

  cout << result << endl;
}
