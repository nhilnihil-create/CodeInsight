#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

long long gcd(long long a, long long b) {
    if(a%b == 0) {
        return b;
    } else {
        return gcd(b, a%b);
    }
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}
 
int main() {
    int n; std::cin >> n;
    std::vector<long long> t(n);
    for(int i = 0; i < n; i++) {
        std::cin >> t[i];
    }

    long long ans;
    if(n != 1) {
    ans = lcm(t[0], t[1]);
    for(int i = 2;i < n; i++) {
        ans = lcm(ans, t[i]);
    }
    } else {
        ans = t[0];
    }

    std::cout << ans << std::endl;
}