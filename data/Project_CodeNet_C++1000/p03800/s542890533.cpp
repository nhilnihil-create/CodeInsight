#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  string s ;
  cin >> s;
  
  s[n]=s[0];
  string t[4]={"SS","SW","WS","WW"};
  
  for(int i=0;i<4;i++){
    for(int j=1;j<n+1;j++){
      if(t[i].substr(j-1,2)=="SS"){
        if(s[j]=='o'){
          t[i]+='S';
        }
        else{
          t[i]+='W';
        }
      }
      if(t[i].substr(j-1,2)=="SW"){
        if(s[j]=='o'){
          t[i]+='W';
        }
        else{
          t[i]+='S';
        }
      }
      if(t[i].substr(j-1,2)=="WS"){
        if(s[j]=='o'){
          t[i]+='W';
        }
        else{
          t[i]+='S';
        }
      }
      if(t[i].substr(j-1,2)=="WW"){
        if(s[j]=='o'){
          t[i]+='S';
        }
        else{
          t[i]+='W';
        }
      }
    }
    if(t[i].substr(0,2)==t[i].substr(n,2)){
      cout << t[i].substr(0,n) << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
