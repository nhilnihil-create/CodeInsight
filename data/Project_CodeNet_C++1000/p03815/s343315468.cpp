#include<iostream>

int main()
{
    long long int n,ans;
    std::cin>>n;
    ans = n/11;
    if(n%11==0){
        std::cout<<ans*2<<std::endl;
    }
    else if(n%11<7){
        std::cout<<ans*2+1<<std::endl;
    }
    else{
        std::cout<<ans*2+2<<std::endl;
    }
}
