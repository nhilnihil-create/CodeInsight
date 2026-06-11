#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, x;
  cin >> N >> K;
  int total = 0;
  for (int i = 0; i < N; i++) {
    cin >> x;
    if (x * 2 <= K) {
      total = total + x;
    }
    else if (x * 2 > K) {
      total = total + K - x;
    }
  }
  cout << total * 2 << endl;
}
    