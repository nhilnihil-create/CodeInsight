#include <iostream>

int main(void){
    int ans = 0;
    std::string S;
    std::cin >> S;
    int N = S.size();

    for (int i = 1; i < N; ++i){
        std::string s = S.substr(0, N - i);
        int n = s.size();
        if (n % 2 == 0){
            if (s.substr(0, n / 2) == s.substr(n / 2, n / 2)){
                ans = n;
                break;
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
