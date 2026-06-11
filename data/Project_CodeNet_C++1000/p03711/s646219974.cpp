#include<iostream>
#include<string>
int main(){
    std::string a,b;
    std::string group = "135781012";
    std::cin >> a >> b;
   if(a == "2" || b=="2")std::cout <<"No";
   else if((group.find(a) != std::string::npos)^ (group.find(b) != std::string::npos)) std::cout <<"No";
   else std::cout<<"Yes";
}