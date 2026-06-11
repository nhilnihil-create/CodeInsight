#include<iostream>
main(){
  std::string s;
  std::cin>>s;
  if(s.size()>=4){
    std::string t="YAKI";
    if(t==s.substr(0,4))puts("Yes");
    else puts("No");
  }
  else puts("No");
}