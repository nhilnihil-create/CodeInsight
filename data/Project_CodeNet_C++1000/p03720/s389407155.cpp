// ABC 061 B- Counting Roads
// 配列の練習

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
  int N, M;
  cin >> N >> M;

  // 二つの都市を結ぶから、道の数×2を配列数にすればよい…はず
  vector<int> vec1(2 * M);
  rep(i, 2 * M) {
    cin >> vec1.at(i);
  }
  // N個の配列を初期値０で作って、一致したら数増やす
  vector<int> vec2(N, 0);
  rep(i, N) {
    rep(j, 2 * M){
      if (i + 1 == vec1.at(j)) {
        vec2.at(i) += 1; // カウント,数はNこ
      }
    }
  }
  // 出力
  rep(i, N) {
    cout << vec2.at(i) << endl;
  }
}