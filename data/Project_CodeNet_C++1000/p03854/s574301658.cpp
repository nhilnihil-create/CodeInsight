#include "bits/stdc++.h"
using namespace std;

int main(){
  vector<string> v = {"dream", "dreamer", "erase", "eraser"};

  string S;
  cin >> S;

  // 後ろから解くかわりにすべての文字列を「左右反転」する
  reverse(S.begin(), S.end());
  //cout << S << endl;

  for(int i = 0; i < v.size(); i++){
    reverse(v[i].begin(), v[i].end());
  }
  /*
  for(int i = 0; i < v.size(); i++){
    cout << v[i] << endl;
  }
  */

 // 一致するか
  bool match = true;
  for(int i = 0; i < S.size(); ){
    bool sw = false;
    for(int j = 0; j < v.size(); j++){
      string str = v[j];
      if(S.substr(i, str.size()) == str){
        sw = true;
        i += str.size();
        break;
      }
    }
    if(!sw){
      match = false;
      break;
    }
  }

  if(match){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}