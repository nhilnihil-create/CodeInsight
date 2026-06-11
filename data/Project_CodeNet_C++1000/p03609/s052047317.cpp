#include<iostream>

int main(){
    int X, t;
    std::cin >> X >> t;
    if(t >= X) std::cout << 0 << std::endl;
    else std::cout << X - t << std::endl;
    return 0;
}
