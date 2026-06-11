
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>
#include <cstdint>
#include <iomanip>
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main(){
    int k,s; std::cin >> k >> s;

    int ans=0;
    for(int x=0; x<=k; x++){
        for(int y=0; y<=k; y++){
            if( s-k <= x+y && x+y <= s ) ans++;
        }
    }

    std::cout << ans << "\n";
    return 0;
}
