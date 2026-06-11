#include <iostream>

int main(void){
    int a, b;
    std::string ans="Positive";
    std::cin >> a >> b;
    if (a <= 0 && b >= 0){
        ans = "Zero";
    } else if (b < 0) {
        int d = b - a;
        if (d % 2 == 0){
            ans = "Negative";
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
