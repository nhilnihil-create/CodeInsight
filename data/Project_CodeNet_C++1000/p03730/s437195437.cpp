#include<iostream>
#include<string>

int main() {
    int a, b, c; std::cin >> a >> b >> c;

    int mod = a%b;
    int plus = a;

    a += plus;
    bool f;
    while(1) {
        if(a%b == c) {
            f = true;
            break;
        } else if(a%b == mod) {
            f = false;
            break;
        }
        a += plus;
    }

    std::string ans = f?"YES":"NO";

    std::cout << ans << std::endl;


}