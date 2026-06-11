#include<bits/stdc++.h>
using namespace std;
int main(){
  char s[200000];
  cin >> s;
  cout << s[0] << strlen(s)-2 << s[strlen(s)-1];
  /*
  bool b;
  for(char i='a';i<='z';i++){
    b=false;
    for(int j=0;j<strlen(s);j++){
      if(s[j]==i){
        b=true;
        break;
      }
    }
    if(!b){
      cout << i << endl;
    }
  }
  if(b)cout << "None";
  */
}
