#include <bits/stdc++.h>
using namespace std;

int main() {
  // ここにプログラムを追記
  int rows_of_square, white_square, black_square;
  cin >> rows_of_square >> white_square;
  
  black_square = rows_of_square * rows_of_square - white_square;
  cout << black_square << endl;
}