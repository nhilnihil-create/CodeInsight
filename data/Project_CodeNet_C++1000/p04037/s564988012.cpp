#include <iostream>
#include <algorithm>

int as[100001];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
  }
  std::sort(as,as+N);
  std::reverse(as,as+N);
  for(int i=0;;i++){
    if(as[i+1]<=i+1){
      int j=i;
      while(as[j+1]>i) j++;
      if((j-i)%2||(as[i]-i-1)%2){
	std::cout<<"First"<<std::endl;
      }else{
	std::cout<<"Second"<<std::endl;
      }
      return 0;
    }
  }
}
