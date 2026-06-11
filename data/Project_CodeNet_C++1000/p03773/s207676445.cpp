#include <iostream>
using namespace std;
int main(void){
  
  int a,b;
  cin>>a>>b;
  int c=a+b;
  
  if(c==24){
      cout<<0<<endl;
  }
  
  else if(c>24){
      cout<<c-24<<endl;
  }
  
  else{
      cout<<c<<endl;
  }
}
