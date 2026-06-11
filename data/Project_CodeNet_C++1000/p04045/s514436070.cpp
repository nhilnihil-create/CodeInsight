#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  vector<int> A(K);
  for (int i = 0; i < K; i++) cin >> A.at(i);

  int cnt = N;

  while (1) {
    bool flag = true;
    while (cnt > 0) {
      int num = cnt % 10;
      for (int i = 0; i < K; i++) {
        if (num == A.at(i)) {
          flag = false;
          break;
        }
      }
      cnt /= 10;
    }
    if (flag) break;
    N++;
    cnt = N;
  }

  cout << N << endl;
}