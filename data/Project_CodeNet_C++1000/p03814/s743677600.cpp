#include<iostream>
#include<string>
using namespace std;
int main(){

  int minA=-1;
  int maxZ=999999;
  string s;
  cin>>s;
  for(int i=0;i<=(int)s.length()-2;i++){
  
    if(s[i]=='A'){
      minA=i+1;
      break;
    }
  }
  for(int j=(int)s.length()-1;j>=0;j--){
  
    if(s[j]=='Z'){
    
      maxZ=j+1;
      break;
    }
  }
  cout<<maxZ-minA+1;
}