#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, total = 0; // ボールの数、ロボットBの位置、総移動距離
  cin >> N >> K;

  for (int i = 0; i < N; i++) {
      int x; // i個目のボールの位置
      cin >> x;
      int a = x * 2;
      int b = abs(K - x) * 2;
      total += (a > b ? b : a);
  }
  cout << total << endl;
}
