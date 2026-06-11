#include <iostream>

int main(void){
    int a, b, c, ans=0;
    std::cin >> a >> b >> c;

    if (a == b && b == c && a % 2 == 0) {
        ans = -1;
    } else {
        while (a % 2 == 0 && b % 2 == 0 && c % 2 == 0){
            int d, e, f;
            d = b / 2 + c / 2;
            e = c / 2 + a / 2;
            f = a / 2 + b / 2;
            a = d, b = e, c = f;
            ++ans;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
