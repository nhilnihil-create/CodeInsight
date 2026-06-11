#include<iostream>
int main(){
    int n;
    std::cin >> n;
    std::cout << (1 + n) * (n/2) + (n/2 + 1)*(n%2);
}