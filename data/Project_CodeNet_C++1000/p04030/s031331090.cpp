#include <bits/stdc++.h>
using namespace std;

int main(){
  string s,ans="";
  cin >> s;
  for(int i=0; i<s.size(); i++){
    if(s.at(i) == '0') ans += "0";
    else if(s.at(i) == '1') ans += "1";
    else if(s.at(i) =='B'){
      if(!i==0 && !ans.empty()){
        ans.pop_back();
      }
    }
  }
  cout << ans << endl;
}
