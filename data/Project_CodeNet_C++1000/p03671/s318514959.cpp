#include<iostream>
#include<algorithm>

int main(){
    int a, b, c;
    std::cin >> a >> b >> c;
    std::cout << std::min({a + b, b + c, c + a}) << std::endl;
    return 0;
}
