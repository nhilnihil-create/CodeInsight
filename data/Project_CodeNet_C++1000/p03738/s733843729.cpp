#include <iostream>
#include <string>
using namespace std;

int main(void){
  string a,b;
  cin>>a>>b;
  
  int digitA=a.size();
  int digitB=b.size();
  
  if(digitA>digitB){
   cout<<"GREATER"<<endl; 
  }else if(digitA<digitB){
   cout<<"LESS"<<endl; 
  }else{
    int i;
   for(i=0;i<digitA;i++){
     if(a[i]>b[i]){
       cout<<"GREATER"<<endl; 
       break;
     }
     else if(a[i]<b[i]){
       cout<<"LESS"<<endl;
     	break;
     }
   }
    if(i==digitA)cout<<"EQUAL"<<endl;
  }
  return 0;
  
}