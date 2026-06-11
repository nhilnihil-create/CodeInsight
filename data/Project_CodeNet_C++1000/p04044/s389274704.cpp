#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);
    int n = 0, l = 0;
    std::cin >> n >> l;
    std::cin.ignore();
    std::vector<std::string> v;
    while (n--) {
        std::string s;
        std::getline(std::cin, s);
        v.emplace_back(s);
    }

    std::sort(v.begin(), v.end());
    for (const std::string& s : v)
        std::cout << s;
    std::cout << std::endl;

    return 0;
}
