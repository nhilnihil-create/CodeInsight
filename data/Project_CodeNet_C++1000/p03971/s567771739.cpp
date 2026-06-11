#include <bits/stdc++.h>
std::string ans[2] = {"No\n", "Yes\n"};
int main() {
    int n, a, b;
    std::cin >> n >> a >> b;
    std::string s;
    std::cin >> s;

    int passed        = 0;
    int abroad_passed = 0;
    for (int i = 0; i < n; ++i) {
        if (s.at(i) == 'a') {
            bool isPass = passed < a + b;
            std::cout << ans[isPass];
            passed += isPass;
        }
        if (s.at(i) == 'b') {
            bool isPass = (passed < a + b && abroad_passed < b);
            std::cout << ans[isPass];
            passed += isPass;
            abroad_passed += isPass;
        }
        if (s.at(i) == 'c') {
            std::cout << ans[0];
        }
    }
    return 0;
}