#include <iostream>
#include <string>

int main(){
  using namespace std;
  string str;
  cin>>str;
  
  for(int i=0;i<19;i++){
   if(str[i]==',')cout<<" ";
    else cout<<str[i];
  }
  return 0;
}