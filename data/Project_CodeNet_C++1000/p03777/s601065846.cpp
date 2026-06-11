#include <iostream>
#include <string>
using namespace std;

int main(void){
  char A,T;
  cin>>A>>T;
  
  if(A=='H'){
   cout<<T<<endl; 
  }else{
   if(T=='H')cout<<'D'<<endl;
   else cout<<'H'<<endl;
  }
  return 0;
}