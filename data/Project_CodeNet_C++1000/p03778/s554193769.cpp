#include<iostream>
#include<algorithm>

int main() {
    int w, a, b;
    std::cin >> w >> a >> b;

    if(b -(w+a) >= 0 || a - (w+b) >= 0) {
        if(b - (w+a) >= 0) {
            std::cout << b - (w + a) << "\n";
        } else if(a - (w+b) >= 0) {
            std::cout << a - (w + b) << "\n";
        }
    } else {
        std::cout << 0 << "\n";
    }
}