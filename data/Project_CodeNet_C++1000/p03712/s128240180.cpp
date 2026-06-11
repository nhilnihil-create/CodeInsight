/*
  Contest 062
  B - Picture Frame
  Rakesh Kumar --> 28/08/2020
 */

#include <bits/stdc++.h>



int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int h = 0, w = 0;
    std::cin >> h >> w;
    std::cin.ignore();
    std::string top(w + 2, '#');

    std::vector<std::string> v;
    while (h--) {
        std::string s;
        std::getline(std::cin, s);
        v.emplace_back(s);
    }

    std::cout << top << std::endl;
    for (const std::string& s : v)
        std::cout << "#" << s << "#" << std::endl;
    std::cout << top << std::endl;

    return 0;
}
