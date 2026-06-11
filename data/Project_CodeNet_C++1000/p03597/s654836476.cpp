#include <bits/stdc++.h>
using namespace std;

int main() {
  // N*Nのマス目
  int masuN = 0;
  // 白色のマス
  int whiteMasu = 0;
  
  // N*Nのマス目と白色のマスを入力
  cin >> masuN >> whiteMasu;
  
  // 黒色のマスを出力
  cout << masuN * masuN - whiteMasu << endl;
}