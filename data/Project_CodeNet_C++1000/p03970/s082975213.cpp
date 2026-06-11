#include<iostream>
main(){
  std::string s;
  std::cin>>s;
  std::string t="CODEFESTIVAL2016";
  int n=s.size();
  int ans=0;
  for(int i=0;i<n;++i)if(s[i]!=t[i])ans++;
  std::cout<<ans<<std::endl;
}