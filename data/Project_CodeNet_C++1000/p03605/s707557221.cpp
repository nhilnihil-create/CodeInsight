/*
  Contest 073
  A - September 9
  Rakesh Kumar --> 11/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    std::string s;
    std::getline(std::cin, s);
    std::string r = "No";
    for (char c : s){
        if (c == '9') {
            r = "Yes";
            break;
        }
    }
    std::cout << r << std::endl;

    return 0;
}
