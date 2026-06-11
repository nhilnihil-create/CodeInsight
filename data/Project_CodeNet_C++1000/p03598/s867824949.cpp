#include<iostream>
int main(){
  int N,K,dist=0,a;
  std::cin>>N>>K;
  for(int i=0;i<N;i++){
    std::cin>>a;
    if(a<=K/2){
      dist+=a*2;
    }else dist+=(K-a)*2;
  }
  std::cout<<dist<<std::endl;
  return 0;
}