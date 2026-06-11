#include<iostream>
#include<string>
int main(){
    std::string N;
    std::cin >> N;
    std::cout << (N[0] == N[2] ? "Yes" : "No");
}