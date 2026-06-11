#include <iostream>
using namespace std;

int main(void){
  int w,a,b;
  cin>>w>>a>>b;
  
  int A=a+w;
  int B=b+w;
  
  if(A<b){
   cout<<b-A<<endl; 
  }else if(B<a){
   cout<<a-B<<endl; 
  }else{
   cout<<'0'<<endl; 
  }
  return 0;
}