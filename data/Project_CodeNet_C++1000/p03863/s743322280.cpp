#include<iostream>
main(){std::string s;std::cin>>s;std::cout<<(s[0]==s.back()^s.size()%2?"First":"Second")<<'\n';}