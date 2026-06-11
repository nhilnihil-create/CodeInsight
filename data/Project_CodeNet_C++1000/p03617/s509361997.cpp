#include<iostream>
int main(){
  long long int Q,H,S,D,N,min_2=0,sub_min;
  std::cin>>Q>>H>>S>>D>>N;
  min_2=std::min(Q*8,std::min(std::min(H*4,S*2),D));
  sub_min=std::min(Q*4,std::min(H*2,S));
  if(N%2==0){
    std::cout<<min_2*N/2<<std::endl;
  }else 
    std::cout<<sub_min+(min_2*((N-1)/2))<<std::endl;
  return 0;
}