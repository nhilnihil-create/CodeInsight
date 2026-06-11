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
    int n;
    std::cin >> n;
    std::vector<int> a(n,0);
    rep(i,n) std::cin >> a[i];

    a.erase(std::unique(a.begin(), a.end()), a.end());

    int ans = 1;
    for(int i=1; i<a.size()-1; i++){
        if(a[i-1]<=a[i] && a[i]<=a[i+1]) continue;
        if(a[i-1]>=a[i] && a[i]>=a[i+1]) continue;
        ans++;
        i++;
    }

    std::cout << ans << "\n";
    return 0;
}
