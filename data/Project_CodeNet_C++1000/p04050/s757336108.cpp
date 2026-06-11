#include <iostream>
#include <vector>
#include <algorithm>

int as[100000];

int main(){
  int N,M;
  std::cin>>N>>M;
  int odd=0;
  for(int i=0;i<M;i++){
    std::cin>>as[i];
    if(as[i]%2){
      std::swap(as[i],as[odd++]);
    }
  }
  if(odd>2){
    std::cout<<"Impossible"<<std::endl;
    return 0;
  }
  
  std::vector<int> bs;
  if(M==1){
    bs.push_back(1);
    if(as[0]>1){
      bs.push_back(as[0]-1);
    }
  }else{
    std::swap(as[1],as[M-1]);
  
    bs.push_back(as[0]+1);
    for(int i=1;i<M-1;i++){
      bs.push_back(as[i]);
    }
    if(as[M-1]>1){
      bs.push_back(as[M-1]-1);
    }
  }
  for(int i=0;i<M;i++){
    if(i>0) std::cout<<" ";
    std::cout<<as[i];
  }
  std::cout<<std::endl;
  std::cout<<bs.size()<<std::endl;
  for(int i=0;i<bs.size();i++){
    if(i>0) std::cout<<" ";
    std::cout<<bs[i];
  }
  std::cout<<std::endl;
  return 0;
}
