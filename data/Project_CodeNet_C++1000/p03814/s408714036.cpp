#include <iostream>
#include <string>
using namespace std;
int main(){
  string s;
  cin >> s;
  int i;
  int st,en;
  for(i=0;i<s.size();i++){
    if(s[i]=='A'){
      st=i;
      break;
    }
  }
  for(i=s.size()-1;i>st;i--){
    if(s[i]=='Z'){
      en=i;
      break;
    }
  }
  //  cout << s.substr(st,en) << "\n";
  cout << en-st+1 << "\n";
  return 0;
}