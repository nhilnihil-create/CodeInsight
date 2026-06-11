#include <iostream>

int main(void){
    int A, B, C, X;
    std::string ans = "NO";
    std::cin >> A >> B >> C;

    for (int i = 0; i < B; ++i){
        X = A * (i + 1);
        if (X % B == C){
            ans = "YES";
            break;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
