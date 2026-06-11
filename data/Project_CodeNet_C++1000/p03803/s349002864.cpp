#include <iostream>
using namespace std;

int main(){
  int A,B;
  cin>>A>>B;
  
  if(A==1){
     if(B!=1){
       cout<<"Alice"<<endl;
     }else{
       cout<<"Draw"<<endl;
     }
  }else if(B==1){
   cout<<"Bob"<<endl; 
  }else{
    if(A>B)cout<<"Alice"<<endl;
    else if(A<B)cout<<"Bob"<<endl;
    else cout<<"Draw"<<endl;
  }
  
  return 0;
}