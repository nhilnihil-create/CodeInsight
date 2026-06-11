#include <bits/stdc++.h>
using namespace std;

int main() {
  string S, s;
  cin >> S;
  s="abcdefghijklmnopqrstuvwkyz";
  string ans="None";
  
  bool f=false;
  for(int i=0; i<26; i++){
    for(int j=0; j<S.size(); j++){
      if(s.at(i)==S.at(j)){
        break;
      }
      if(j==S.size()-1){
        ans=s.at(i);
        f=true;
        break;
      }
    }
    if(f)break;
  }
  
  cout << ans << endl;

}