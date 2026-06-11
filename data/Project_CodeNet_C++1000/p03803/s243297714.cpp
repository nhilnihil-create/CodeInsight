#include<iostream>
using namespace std;

int main(){
  int A,B;
  cin>>A>>B;
  if(A==1||B==1){
    if(A==1&&B!=1){
      cout<<"Alice"<<endl;
    }else if(A!=1&&B==1){
      cout<<"Bob"<<endl;
    }else{
      cout<<"Draw"<<endl;
    }
  }else{
    if(A==B){
      cout<<"Draw"<<endl;
    }else{
      cout<<(A<B?"Bob":"Alice")<<endl;
    }
  }
  return 0;
}
