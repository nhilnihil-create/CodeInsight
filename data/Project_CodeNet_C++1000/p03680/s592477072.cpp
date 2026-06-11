#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, number, bit, count;
  cin >> N;
  vector<int> button(N, 0);
  
  for (int i = 0; i < N; i++) {
    cin >> button.at(i);
  }

  count = 0;
  bit = 0;
  number = 1; // 次に押そうとしているボタンの番号名（光ったボタン）

  // ボタン i を探す

  for (int i = 0; i < N; i++) {
    count++; // ボタンを押したので押した数をカウント
    number = button.at(number - 1); // 押したことで光るボタン＝ボタンが指し示していた数字を格納
	if (number == 2) {
      bit = 1;
      break;
    }
  }
  
  if (bit == 1) {
    cout << count << endl; 
  }
  else {
    cout << -1 << endl;
  }
}