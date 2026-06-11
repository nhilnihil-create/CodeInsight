#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  vector<string> T={"dream","dreamer","erase","eraser"};
  reverse(S.begin(),S.end());
  for(int i=0;i<4;i++){
    reverse(T.at(i).begin(),T.at(i).end());
  }
  bool all_cut=true;
  for(int i=0;i<S.size();){
    bool cut=false;
    for(int j=0;j<4;j++){
      string U=S.substr(i,T.at(j).size());
      if(U==T.at(j)){
        i+=T.at(j).size();
        cut=true;
        break;
      }
    }
    if(!cut){
      all_cut=false;
      break;
    }
  }
  if(all_cut){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}