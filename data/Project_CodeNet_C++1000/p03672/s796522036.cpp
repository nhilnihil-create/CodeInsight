#include <bits/stdc++.h>
#include <vector>

using namespace std;

 bool even(string s){

  int len = s.size();

  for(int i=0;i<len/2;i++){
     if(s[i] != s[i+len/2]){
        return false;
          }
  }

  return true;
 }

int main(){

 string s;
 cin>>s;
 int len = s.size(),dec=2,ans;

 while(s.size() >= 2){

     s = s.substr(0,len-dec);

    if(even(s)){
    ans = s.size();

    break; }
   dec += 2;
 }

 cout<<ans<<endl;

 return 0;
 }
