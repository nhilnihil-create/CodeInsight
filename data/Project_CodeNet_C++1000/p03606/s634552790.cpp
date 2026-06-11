#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, total = 0;
  cin >> N;

  // ここにプログラムを追記
  for (int i = 0; i < N; i++) {
    int st, ed;
    cin >> st >> ed;
    total += (ed - st + 1);
  }
  cout << total << endl;
}
