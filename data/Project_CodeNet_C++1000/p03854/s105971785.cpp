#include "bits/stdc++.h"
using namespace std;

// n文字目以降の文字がうまく切れるかを計算
bool dfs(int n, vector<string> &v, string S){
  if(n == S.size()){
    return true;
  }
  for(auto str: v){
    if(n + str.size() <= S.size() && S.substr(n, str.size()) == str){
      if(dfs(n + str.size(), v, S)){
        return true;
      }
    }
  }
  return false;
}

int main(){
  vector<string> v = {"dream", "dreamer", "erase", "eraser"};

  string S;
  cin >> S;

  if(dfs(0, v, S)){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}