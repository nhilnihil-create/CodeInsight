#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include<cmath>

#define mod 1000000007

long long fact(long long a) {
    long long r = 1;
    for(long long i = 2; i <= a; i++) {
        r *= i;
        r %= mod;
    }

    return r%mod;
}

long long calc(long long n, long long m) {
    return (fact(n)*fact(m))%mod;
}

int main() {
    long long n, m; std::cin >> n >> m;

    long long ans;

    if(std::abs(n-m) > 1) {
        ans = 0;
    } else if(n == m) {
        ans = 2*calc(n, m);
    } else {
        ans = calc(n, m);
    }

    std::cout << ans%mod << std::endl;
}