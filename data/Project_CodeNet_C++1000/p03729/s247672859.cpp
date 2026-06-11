#include<iostream>
#include<string>
int main(){
    std::string a, b, c;
    std::cin >> a >> b >> c;
    std::cout << (*(a.end()-1) == b[0] && *(b.end()-1) == c[0] ? "YES" : "NO");
}