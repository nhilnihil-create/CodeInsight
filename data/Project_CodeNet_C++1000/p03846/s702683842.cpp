#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include<set>
#define mod 1000000007

int main() {
    int n; std::cin >> n;
    std::set<int> an;

    std::vector<int> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
        an.insert(a[i]);
    }

    bool iszero = false;
    std::sort(a.begin(), a.end());

    for(auto itr = an.begin(); itr != an.end(); itr++) {
        int num = std::upper_bound(a.begin(), a.end(), *itr) - std::lower_bound(a.begin(),a.end(), *itr);
        if(num != 2 && *itr != 0) {
            iszero = true;
        }
    }

    int power = n / 2;

    long long ans = 1;
    for(int i = 0; i < power; i++) {
        ans *= 2;
        ans %= mod;
    }

    if(iszero) {
        ans = 0;
    }

    std::cout << ans << std::endl;

}