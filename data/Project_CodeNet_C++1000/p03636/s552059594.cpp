#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

int main() {
    std::string s;
    std::cin >> s;

    int num = s.size() - 2;

    std::cout << s[0] << num << s[s.size() - 1] << "\n";
}