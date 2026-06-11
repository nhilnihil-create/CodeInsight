#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int strengths[3 * N];
  for (int i = 0; i < 3 * N; i++) cin >> strengths[i];

  // 5 2 8 5 1 5 → 8 5 5 5 2 1 に並び替える
  // (8, 5, ?), (5, 5, ?) のように強いカードを 2 枚ずつ消費する
  long int sum = 0;
  sort(strengths, strengths + 3 * N, greater<>());
  for (int i = 0; i < 2 * N; i++) {
    // 中央の値を加算する
    if (i % 2 == 1) sum += strengths[i];
  }
  cout << sum << endl;
}