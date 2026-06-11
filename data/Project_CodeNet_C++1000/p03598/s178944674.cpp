#include <bits/stdc++.h>
using namespace std;
// Collecting Balls (Easy Version)
int main() {
  int N, K, s = 0;
  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;

    if (x <= K / 2) {
      s += x;
    } else {
      s += K - x;
    }
  }

  cout << s * 2 << endl;
}