#include <bits/stdc++.h>
using namespace std;

int main() {
  int side_num = 0;
  int paint_white_num = 0;
  // 入力
  cin >> side_num >> paint_white_num;
  
  // 出力
  cout << side_num * side_num - paint_white_num << endl;
}