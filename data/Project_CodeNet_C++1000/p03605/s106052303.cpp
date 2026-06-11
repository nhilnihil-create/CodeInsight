#include<iostream>
int main(){
    int N;
    std::cin >> N;
    std::cout << (N >= 90 || N%10 == 9 ? "Yes" : "No");
}