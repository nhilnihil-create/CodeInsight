#include<bits/stdc++.h>
#define CF {std::cout<<"First\n";return 0;}
#define CS {std::cout<<"Second\n";return 0;}
std::string s;
int main(){
    std::cin>>s;int l=s.size();
    if(s[0]==s[l-1])if(l%2)CS else CF
    else if(l%2)CF else CS
}