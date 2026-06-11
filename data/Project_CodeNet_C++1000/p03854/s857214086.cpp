#include "bits/stdc++.h"
using namespace std;

int main(){
  vector<string> v = {"dream", "dreamer", "erase", "eraser"};
  // テスト用(たまたまはありえず必ずうまくいく)
  //vector<string> v = {"erase", "dreamer", "erased", "eraser", "ream"};
  vector<bool> check(100000);

  string S;
  cin >> S;

  check[0] = 1; // 次に調べる位置に1を代入
  for(int i = 0; i < S.size(); i++){
    if(!check[i])continue;  // 次に調べる位置までスキップ
    for(auto str: v){ // 次に調べる位置すべてに1を代入 
      if(S.substr(i, str.size()) == str){
        check[i + str.size()] = 1;
      }
    }
  }
  if(check[S.size()] == 1){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }

}