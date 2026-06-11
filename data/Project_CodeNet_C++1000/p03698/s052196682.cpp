#include <bits/stdc++.h>
using namespace std;
 
int main(){
  string s;
  cin >> s;
  
  string ans="yes";
  for(int i=0;i<s.size()-1;i++){
    for(int j=i+1;j<s.size();j++){
      if(s.at(i)==s.at(j)){
        ans="no";
        break;
      }
    }
  }
  cout << ans << endl;
}