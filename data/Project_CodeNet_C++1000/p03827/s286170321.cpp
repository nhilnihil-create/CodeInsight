#include <iostream>

int main(void){
    int N, ans=0, tmp=0;
    std::string S;
    std::cin >> N >> S;

    for (char c: S){
        if (c == 'I') ++tmp;
        else --tmp;
        if (ans < tmp) ans = tmp;
    }

    std::cout << ans << std::endl;
    
    return 0;
}
