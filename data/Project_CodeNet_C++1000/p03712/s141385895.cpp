#include <bits/stdc++.h>
using namespace std;

int main() {
  //高さH，幅Wを宣言
  int H, W;
  cin >> H >> W;
  
  //文字列を宣言
  vector<vector<char>> s( H ,vector<char>(W));
  
  for (int i = 0; i < H; ++i){
    for (int j = 0; j < W; ++j){
      cin >> s.at(i).at(j) ;
    }
  }
  
  for (int i = 0; i < H+2; ++i){
    if(i == 0 || i == H+1){
      for (int j=0 ;j < W+2 ;++j ){
        cout << '#' ;
      }
      cout << endl;
    }
    else {
      cout << '#';	
        for (int j = 0; j < W; ++j){
        cout << s.at(i-1).at(j) ;
      }
      cout << '#' << endl;
   }
  }
}
