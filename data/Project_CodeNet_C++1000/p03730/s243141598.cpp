#include<iostream>
int main(){
  int A,B,C;
  std::cin>>A>>B>>C;
  for(int i=1;i<=B;i++){
    if(A*i%B==C){
      std::cout<<"YES"<<std::endl;
      return 0;
    }
  }
  std::cout<<"NO"<<std::endl;
  return 0;
}