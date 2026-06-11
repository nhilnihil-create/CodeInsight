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
    int n; std::cin >> n;
    std::vector<int> s(n,0);
    for(int i=0; i<n; i++){
        std::cin >> s[i];
    }

    std::sort(s.begin(),s.end());

    int ans = std::accumulate(s.begin(),s.end(),0);
    if(ans%10==0){
        for(int i=0; i<n; i++){
            if(s[i]%10!=0){
                std::cout << ans-s[i] << "\n";
                return 0;
            }
        }
    }else{
        std::cout << ans << "\n";
        return 0;
    }
    std::cout << 0 << "\n";
    return 0;
}
