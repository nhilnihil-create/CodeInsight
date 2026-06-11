#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  bool flag = false;
  if (K % N == 0 || K % M == 0) {
    flag = true;
  } else {
    for (int i = 1; i < N; i++) {
      for (int j = 1; j < M; j++) {
        // cout << i << "," << j << ":" << M * i + N * j - (2 * i * j) << endl;
        if (M * i + N * j - (2 * i * j) == K) {
          flag = true;
        }
      }
    }
  }

  if (flag == true) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}