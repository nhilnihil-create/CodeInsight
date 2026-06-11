/*
  A - Addition and Subtraction Easy
  Contest 050
  Rakesh Kumar --> 03/08/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    std::string s;
    std::getline(std::cin, s);
    std::istringstream iss(s);
    int a = 0, b = 0;
    char o = ' ';
    iss >> a >> o >> b;
    if (o == '+')
        std::cout << a + b << std::endl;
    else
        std::cout << a - b << std::endl;

    return 0;
}
