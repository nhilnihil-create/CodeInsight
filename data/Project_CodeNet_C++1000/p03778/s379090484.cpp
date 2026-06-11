#include<iostream>
using namespace std;
 
int main(){
  int W,a,b;
  while(cin>>W>>a>>b){
    if(b+W>=a&&b<=a+W)
      cout<<0<<endl;
    else if(b>a+W)
      cout<<b-a-W;
    else
      cout<<a-b-W;
  }
  return 0;
}