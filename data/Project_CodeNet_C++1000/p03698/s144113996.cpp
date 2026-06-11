#include<iostream>
#include<string>
using namespace std;
int main(){

  string S;
  cin>>S;
  bool flag=0;
  for(int i=1;i<=(int)(S.length()-1);i++){
  
    for(int j=0;j<=i-1;j++){
    
      if(S[j]==S[i]){
      
        flag=1;
        break;
      }
    }
    if(flag==1)break;
  }
  if(flag==1)cout<<"no";
  else cout<<"yes";
  return 0;
}