#include <iostream>
#include <cmath>

int main()
{
    long long x,y;
    std::cin>>x>>y;
    if(std::abs(x-y)<=1){
        std::cout<<"Brown\n";
    }else{
        std::cout<<"Alice\n";
    }
}

