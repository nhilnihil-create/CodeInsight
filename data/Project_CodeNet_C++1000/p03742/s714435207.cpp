#include<iostream>    
#include <climits>
#include <functional>
int main()
    {
        long long X, Y;
        std::cin>>X>>Y;
        if (abs(X - Y) <= 1)
            std::cout<<"Brown\n";
        else
            std::cout<<"Alice\n"; 
    }