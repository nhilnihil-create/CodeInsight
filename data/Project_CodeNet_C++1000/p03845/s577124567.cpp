#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> times;
  int sum = 0;
  for (int i = 0; i < N; i++) {
    int t;
    cin >> t;
    times.push_back(t);
    sum += t;
  }

  int M;
  cin >> M;
  // 合計は計算済みであるため、ドリンク適用後の時間を差分計算する
  for (int i = 0; i < M; i++) {
    int p, x;
    cin >> p >> x;
    p--;  // 0 base に合わせる

    int time = (sum - times[p]) + x;
    cout << time << endl;
  }
}
