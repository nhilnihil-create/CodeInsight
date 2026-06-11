#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <set>
#include <map>

#define mod 1000000007

int main() {
    long long n; std::cin >> n;

    int a = n;
    int b = 1;
    for(int i = std::sqrt(n); i > 0; i--) {
        if(n%i == 0) {
            a = i;
            b = n/i;
            break;
        }
    }

    std::string A = std::to_string(a);
    std::string B = std::to_string(b);

    std::cout << std::max(A.size(), B.size()) << std::endl;
}