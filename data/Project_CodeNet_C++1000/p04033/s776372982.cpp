#include <iostream>
using namespace std;
int main(void){
  int a,b;
  cin >>a>>b;
  if(a>0){
   cout<<"Positive"; 
  }
  else if(b<0){
    if((b-a)%2==0){
      cout<<"Negative"; 
    }
    else{
      cout<<"Positive"; 
    }
  }
  else{
   cout<<"Zero" ;
  }
}