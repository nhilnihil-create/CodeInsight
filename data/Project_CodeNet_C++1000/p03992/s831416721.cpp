#include<iostream>
main(){
  std::string s;
  std::cin>>s;
  for(int i=0;i<4;++i)std::cout<<s[i];
  std::cout<<" ";
  for(int i=4;i<s.size();++i)std::cout<<s[i];
  std::cout<<std::endl;
}