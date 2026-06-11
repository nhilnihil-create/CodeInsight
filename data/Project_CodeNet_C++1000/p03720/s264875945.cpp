#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  
  // 都市ごとの道路本数を格納する配列
  vector<int> douro_count(N);
  
  // 標準入力から読み込んで、各都市の道路数をカウント
  for (int i = 0; i < M; i++) {
    int toshi1, toshi2;
    cin >> toshi1 >> toshi2;
    // 道路数の加算
    douro_count.at(toshi1 -1) += 1; // 添字が1ずれている
    douro_count.at(toshi2 -1) += 1;
  }
  // 結果を出力
  for (int i = 0; i < N; i++) {
    cout << douro_count.at(i) << endl;
  }
return 0;
}