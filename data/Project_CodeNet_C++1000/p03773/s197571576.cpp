#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <regex>
#include <set>
#include <cmath>
#include <sstream>
#include <numeric>
#include <set>

using namespace std;

int main()
{
    int a, b;
    std::cin >> a >> b;
    std::cout << (a + b) % 24;

    return EXIT_SUCCESS;
}
