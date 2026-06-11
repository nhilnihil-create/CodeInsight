#include<iostream>
#include<string>
using namespace std;
int main(){

  string A,B;
  cin>>A>>B;
  char a=0;
  char b=0;
  if(A.length()>B.length()){
  
    cout<<"GREATER";
    return 0;
  }
  else if(A.length()<B.length()){
  
    cout<<"LESS";
    return 0;
  }
  for(size_t i=0;i<=A.length()-1;i++){
  
    a=A[i];
    b=B[i];
    if(a>b){
    
      cout<<"GREATER";
      return 0;
    }
    else if(a<b){
    
      cout<<"LESS";
      return 0;
    }
  }
  cout<<"EQUAL";
  return 0;
}