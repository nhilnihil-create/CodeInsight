#include<bits/stdc++.h>
using namespace std;

using tiii = tuple<int,int,int>;

int main(){
  int W, H ,N;
  cin >> W >> H >> N;
  tiii T;
  vector<tiii>A(110);
  
  for(int i =0; i <N; i++){
    cin >> get<0>(A[i]) >> get<1>(A[i]) >> get<2>(A[i]);
  }
  //tuple<x座標，ｙ座標，a>
  int colored_H = 0;
  int colored_W= 0; //塗り潰されたHとW
  int colored_H2= 0;
  int colored_W2= 0;//塗り潰されたHとW(座標(H,W)側からの距離)
  
  for(int i=0; i <N; i++){
    if(get<2>(A[i]) == 1 && colored_W < get<0>(A[i])){ //a == 1のとき，左側を塗りつぶす.すでに塗り潰されていれば無視
      colored_W = get<0>(A[i]);
    }
    else if(get<2>(A[i]) == 2 && colored_W2 < (W - get<0>(A[i]) ) ){
      colored_W2 = W - get<0>(A[i]);
    }
    else if(get<2>(A[i]) == 3 && colored_H < get<1>(A[i]) ){
      colored_H = get<1>(A[i]);
    }
    //↓問題のコード
    else if(get<2>(A[i]) == 4 && colored_H2 < (H - get<1>(A[i]) ) ){
      colored_H2 = H - get<1>(A[i]);
      //ここで出力しない場合，なぜかここでcoloredH2が変更されない
     
      //↑問題のコード　
    }

  }
  
  H -= colored_H + colored_H2;
  W -= colored_W + colored_W2;
  if(H < 0) H = 0;
  if(W < 0) W = 0;
  cout << H * W << endl;
  
  
  
}
