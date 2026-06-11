#include<iostream>
using namespace std;
int main(){

  int a,b;
  cin>>a>>b;
  if(a<=0&&b>=0){
  
    cout<<"Zero";
    return 0;
  }
  else if(a>0){
  
    cout<<"Positive";
    return 0;
  }
  else if(b<0){
  
    if((b-a+1)%2==0){
    
      cout<<"Positive";
      return 0;
    }
    else{
    
      cout<<"Negative";
      return 0;
    }
  }
  return 0;
}