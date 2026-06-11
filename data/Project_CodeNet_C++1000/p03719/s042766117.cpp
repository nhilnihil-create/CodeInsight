#include<iostream>

int main(){
int A,B,C;
  std::cin>>A>>B>>C;
  if(C>=A&&B>=C){
    std::cout<<"Yes";
  }else{
    std::cout<<"No";
  }
  return 0;
  
}