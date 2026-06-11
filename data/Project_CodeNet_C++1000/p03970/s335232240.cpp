#include <iostream>

int main()
{
    std::string s;
    std::cin >> s;

    std::string right = "CODEFESTIVAL2016";

    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != right[i]) {
            ans++;
        }
    }

    std::cout << ans << std::endl;
}
