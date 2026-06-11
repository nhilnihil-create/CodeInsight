/*
  A - Shiritori
  Contest 060
  Rakesh Kumar --> 24/08/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    std::string s;
    std::getline(std::cin, s);
    std::istringstream iss(s);
    std::string a;
    std::string b;
    std::string c;
    iss >> a >> b >> c;
    if (a[a.size() - 1] == b[0] &&
        b[b.size() - 1] == c[0])
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;

    return 0;
}
