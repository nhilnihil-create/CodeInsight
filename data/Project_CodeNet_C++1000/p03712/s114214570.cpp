#include <bits/stdc++.h>
using namespace std;
int main(){
  int H;
  int W;

  //HWを受け取る
  cin >> H;
  cin >> W;

  //入力された文字列を配列で受け取る(H個)
  vector<string> vec(H);
  for (int i =0; i < H; i++){
      cin >> vec.at(i);
  }

  //#をWの数+2でfor出力する
  for (int i = 0; i < W + 1; i++ ){
      cout << "#";
  }
  cout << "#" << endl;

  //配列をHの数だけfor出力する
  //頭と終わりに#をつける
   for (int i = 0; i < vec.size(); i++) {
      cout << "#";
      cout << vec.at(i);
      cout << "#" << endl;
 }
    for (int i = 0; i < W + 1; i++ ){
      cout << "#";
  }
  cout << "#" << endl;

  
}