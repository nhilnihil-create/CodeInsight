#include <iostream>

int main(void){
    int a, b;
    std::string A, B, ans="EQUAL";
    std::cin >> A >> B;
    a = A.size();
    b = B.size();

    if (a > b) {
        ans = "GREATER";
    } else if (a < b){
        ans = "LESS";
    } else {
        for (int i=0; i<a; ++i){
            if (A.at(i) > B.at(i)){
                ans = "GREATER";
                break;
            } else if (A.at(i) < B.at(i)){
                ans = "LESS";
                break;
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
