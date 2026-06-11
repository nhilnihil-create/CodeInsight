#include<iostream>
#include<vector>
std::vector<int>count(100010,0);
int main(){
  int N,ans=0;
  std::cin>>N;
  std::vector<int>a(N);
  for(int i=0;i<N;i++){
    std::cin>>a.at(i);
    count[a.at(i)+1]++;
    count[a.at(i)]++;
    if(a.at(i)==0)continue;
    count[a.at(i)-1]++;
  }
  for(int i=0;i<count.size();i++){
  	ans=std::max(count[i],ans);
  }
  std::cout<<ans<<std::endl;
  return 0;
}
  