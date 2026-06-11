#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>
#include <cstdint>
#include <iomanip>
#include <set>
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main(){
    ll n,a,b; std::cin >> n >> a >> b;

    if(a>b){
        std::cout << 0 << "\n";
        return 0;
    }
    if(n==1 && a==b){
        std::cout << 1 << "\n";
        return 0;
    }
    if(n==1 && a!=b){
        std::cout << 0 << "\n";
        return 0;
    }

    std::cout << ( a + b*(n-1) ) - ( a*(n-1) + b ) + 1 << "\n";
    return 0;
}
