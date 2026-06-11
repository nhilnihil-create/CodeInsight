#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  vector<string> cut={"maerd","remaerd","esare","resare"};
  reverse(S.begin(),S.end());
  bool all_cut=false;
  for(int i=0;;){
    if(i==S.size()){
      all_cut=true;
      break;
    }
    bool exist_cut=false;
    for(int j=0;j<4;j++){
      if(S.substr(i,cut.at(j).size())==cut.at(j)){
        exist_cut=true;
        i+=cut.at(j).size();
        break;
      }
    }
    if(!exist_cut){
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