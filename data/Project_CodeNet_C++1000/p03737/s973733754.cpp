#include<iostream>
#include<string>
int main(){
    std::string a, b, c;
    std::cin >> a >> b >> c;
    std::cout << char(a[0]-0x20) << char(b[0]-0x20) << char(c[0]-0x20);
}