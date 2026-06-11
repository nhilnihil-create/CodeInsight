#include <bits/stdc++.h>
using namespace std;

int main(){
  int N; cin >> N;
  vector<int> dict(N); // 文字列と出現回数の辞書作成

  for (int i=0; i < N; i++) { // 辞書内の文字列xに対応する出現回数を+1する
    int x ;
    cin >> x; // 文字列 x 入力
    dict.at(x)++;
  }
  
  int length;
    for (int i=0; i < N; i++) { 
      if (dict.at(i)){
        length = i;
      }
  }
  int ng_flag = 0;
  if(length%2 == 0){
    for(int i = length; i > length/2 ; i--){
      if(dict.at(i) <= 1){
        ng_flag = 1;
      }
    }
    if(dict.at(length/2)!=1){
      ng_flag = 1;
    }
    for(int i = 0; i < length/2 ; i++){
      if(dict.at(i)){
        ng_flag = 1;
      }
      } 
  }else{
    for(int i = length; i > (length+1)/2 ; i--){
      if(dict.at(i) <= 1){
        ng_flag = 1;
      }
    }
    if(dict.at((length+1)/2)!=2){
      ng_flag = 1;
    }
    for(int i = 0; i < (length+1)/2 ; i++){
      if(dict.at(i)){
        ng_flag = 1;
      }
    }
  }
  if(ng_flag){
    cout << "Impossible" << endl;
  } else {
    cout << "Possible" << endl;
  }
}