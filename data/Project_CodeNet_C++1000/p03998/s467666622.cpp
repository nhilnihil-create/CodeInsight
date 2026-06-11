#include<iostream>
#include<vector>
int main(){
  std::vector<std::string> s(3);
  std::cin>>s[0]>>s[1]>>s[2];
  int t = 0;
  std::vector<int> i(3);
  while(1){
    if(s[t].size()==i[t]){
      std::cout<< char('A'+t) <<std::endl;
      break;
    }
    t = s[t][i[t]++]-'a';
  }
}
