#include <bits/stdc++.h>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;

  // H*Wの配列を読み込む
  vector<vector<char>> pixel(H, vector<char>(W));

  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      
      cin >> pixel.at(i).at(j);

    }
  }

  // (H+2)*(W+2)の配列を宣言し、#で埋める
  vector<vector<char>> table(H + 2, vector<char>(W + 2, '#'));

  // 文字配列を#で囲む
  for(int i = 1; i < H + 1; i++){
    for(int j = 1; j < W + 1; j++){
      
      table.at(i).at(j) = pixel.at(i - 1).at(j - 1); 

    }
  }
  
  for(int i = 0; i < H + 2; i++){
    for(int j = 0; j < W + 2; j++){
      
      cout << table.at(i).at(j);
      
      if(j == W + 1){
        cout << endl;
      }
    }
  }
}