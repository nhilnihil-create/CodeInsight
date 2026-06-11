#include <iostream>
using namespace std;

int main(void){
  int a,b;
  cin>>a>>b;
  
  int time=a+b;
  if(time>=24){
   cout<<time-24<<endl; 
  }else{
   cout<<time<<endl; 
  }
  return 0;
}