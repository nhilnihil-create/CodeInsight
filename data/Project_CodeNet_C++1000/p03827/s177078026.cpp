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
    ll n; std::string s;
    std::cin >> n >> s;

    int x=0, ans=0;
    for(int i=0; i<n; i++){
        if(s[i]=='I') x++;
        else x--;
        ans = std::max(ans, x);
    }
    std::cout << ans << "\n";
    return 0;
}
