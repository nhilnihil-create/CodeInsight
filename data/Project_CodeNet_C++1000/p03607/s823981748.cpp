#include<bits/stdc++.h>

int main(){
  std::map<int,int>a;
  int n,b;
  std::cin>>n;
  for(int i=0;i<n;i++){
    std::cin>>b;
    if(a[b]==1)a.erase(b) ;
    else a[b]++;
  }
  std::cout<<a.size()<<std::endl;
  return 0;
}