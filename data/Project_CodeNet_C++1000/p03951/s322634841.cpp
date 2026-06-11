#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>
#include <cstdint>
#include <iomanip>
#include <set>
#include <map>
#include <unordered_map>
#include <cassert>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main(){
    int n; std::cin >> n;
    std::string s,t;
    std::cin >> s >> t;

    int ans = 2*n;
    for(int i=n-1; i>=0; i--){
        std::string si = s.substr(i);
        std::string ti = t.substr(0,n-i);
        if(si==ti){
            ans = 2*n - si.size();
        }
    }

    std::cout << ans << "\n";
    return 0;
}