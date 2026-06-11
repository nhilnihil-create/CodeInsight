#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
int main(){
  string S;
  cin>>S;
  int i=S.size()-1;
  int judge=0;
  while(judge==0){
    if(i==-1) judge=1;
    else if(S[i]=='r'){
      if(i>=5&&S[i-3]=='a'&&S[i-1]=='e'){
        if(S[i-5]=='e'&&S[i-4]=='r'&&S[i-2]=='s') i-=6;
        else if(i>=6&&S[i-6]=='d'&&S[i-5]=='r'&&S[i-4]=='e'&&S[i-2]=='m'){
          i-=7;
        }
        else judge=1;
      }
      else judge=1;
    }
    else if(i>=4&&S[i-3]=='r'){
      if(S[i-4]=='d'&&S[i-2]=='e'&&S[i-1]=='a'&&S[i]=='m') i-=5;
      else if(S[i-4]=='e'&&S[i-2]=='a'&&S[i-1]=='s'&&S[i]=='e') i-=5;
      else judge=1;
    }
    else judge=1;
  }
  if(i==-1) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  
  return 0;
}