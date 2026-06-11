#include<iostream>
int main(){
    int n, k, x, y;
    std::cin >> n >> k >> x >> y;
    if(k >n) k = n;
    std::cout << (n-k)*y + k*x;
}