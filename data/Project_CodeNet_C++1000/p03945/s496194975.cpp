#include <iostream>
#include <iomanip>
#include <cstdint>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <limits>

int main()
{
    std::string S;
    std::cin >> S;

    int64_t count = 0;
    for (int64_t i = 1; i < S.size(); ++i) {
        char prev_c = S.at(i-1);
        char curr_c = S.at(i);
        if (prev_c != curr_c) count++;
    }

    std::cout << count << std::endl;

    return 0;
}