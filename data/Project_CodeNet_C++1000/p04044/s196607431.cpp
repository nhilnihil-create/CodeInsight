#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N, L;
    std::vector<string> S;
    std::string tmp;
    std::cin >> N >> L;
    for (int i = 0; i < N; i++) {
        std::cin >> tmp;
        S.push_back(tmp);
    }
    std::sort(S.begin(), S.end());
    std::string ans = "";
    for (int i = 0; i < N; i++) {
        ans += S.at(i);
    }
    std::cout << ans << std::endl;
}
