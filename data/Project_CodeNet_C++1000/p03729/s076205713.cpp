#include <bits/stdc++.h>
int main(){
  std::string a,b,c; std::cin>>a>>b>>c;
  std::cout<<(a[a.size()-1]==b[0]&&b[b.size()-1]==c[0]?"YES":"NO");
}