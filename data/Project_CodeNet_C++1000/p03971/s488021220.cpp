#include <iostream>
#include <string>

int main() {
    int n, a, b;
    std::string s;

    std::cin >> n >> a >> b >> s;
    
    int a_count = 0, b_count = 0;
    for (auto c : s) {
        switch (c) {
            case 'a':
                if (a_count + b_count < a + b) {
                    std::cout << "Yes" << std::endl;
                    a_count++;
                } else {
                    std::cout << "No" << std::endl;
                }
                break;
            case 'b':
                if (a_count + b_count < a + b && b_count < b) {
                    std::cout << "Yes" << std::endl;
                    b_count++;
                } else {
                    std::cout << "No" << std::endl;
                }
                break;
            default:
                std::cout << "No" << std::endl;
        }
    }

    return 0;
}