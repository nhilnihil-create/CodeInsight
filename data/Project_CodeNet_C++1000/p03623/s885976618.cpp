#include<iostream>
#include<cmath>
int main(){
    int x, a, b;
    std::cin >> x >> a >> b;
    std::cout << (std::abs(x - a) < std::abs(x - b)? "A" : "B");
}