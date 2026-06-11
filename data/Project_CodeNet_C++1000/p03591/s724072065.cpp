#include<iostream>
#include<vector>
#include<string>

int main(){
    std::string s,r;
    std::cin>>s;
    r ="YAKI";
    
    if(s.substr(0,4)==r){
      std::cout<<"Yes";
    }else{
      std::cout<<"No";
    }
}