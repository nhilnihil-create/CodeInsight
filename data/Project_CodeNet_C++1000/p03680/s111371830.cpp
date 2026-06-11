#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  // 終わりにしたいボタン番号 配列添字の都合で -1
  int finish_no = 2-1;
  // 入力読み込み用の配列
  vector<int> next_button(N);
  
  // 標準入力から読み込み
  for (int i = 0; i < N; i++) {
    cin >> next_button.at(i);
  }
  
  // 答えを探す ボタンの数だけ試せば十分
  int cur_button = 0; // 配列添字の都合でボタン番号 -1
  int cnt = 0;
  for (int i = 0; i < N; i++) {
//    cout << cur_button + 1 << "番のボタンを押したら" << next_button.at(cur_button) << "番のボタンが光りました" << endl;
    // 終わりにしたいボタン番号かどうか判定 ボタン番号と添字の-1に注意
    if (next_button.at(cur_button)-1 == finish_no) {
      cout << i+1 << endl;
      return 0;
    }
    else {
      // カレントボタンを置き換え ボタン番号と添字の-1に注意
      cur_button = next_button.at(cur_button) -1;
    }
}
   
  // 終わりにしたい番号は出なかった
  cout << -1;
  return 0;
}