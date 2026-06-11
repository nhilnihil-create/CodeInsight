#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

int main(){
    int N, L; std::cin >> N >> L;
    std::vector<std::string> S(N);
    for (auto& r : S) std::cin >> r;
    std::sort(S.begin(), S.end());
    for (auto& r : S)std::cout << r;
    std::cout << std::endl;

    return 0;
}