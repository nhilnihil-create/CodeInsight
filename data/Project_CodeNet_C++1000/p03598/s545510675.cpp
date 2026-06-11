#include <bits/stdc++.h>
using namespace std;

int main() {

  int N, K, x, l, M;
  cin >> N >> K;
  l = 0;
  M = K / 2;

  for (int i = 0; i < N; i++) {
    cin >> x;
    if (x <= 0 || x >= K) break;
    else if (x < M) l += x;
    else if (x > M) l += K - x;
    else if (x = M) l += M;
  }

  cout << l * 2 << endl;

}