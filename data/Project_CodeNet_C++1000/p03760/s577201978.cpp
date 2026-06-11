#include <iostream>
#include <string>
using namespace std;

int main(){
  string str1,str2;
  cin>>str1;
  cin>>str2;
  if(str1.size()>str2.size()){
    for(int i=0;i<str2.size();i++){
      cout<<str1[i];
      cout<<str2[i];
    }
    cout<<str1[str1.size()-1];
  }
  else{
    for(int i=0;i<str1.size();i++){
      cout<<str1[i];
      cout<<str2[i];
    }
  }
}