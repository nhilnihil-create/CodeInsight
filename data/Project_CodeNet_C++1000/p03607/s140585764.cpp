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
    int n; std::cin>> n;
    std::set<int> a;
    for(int i=0; i<n; i++){
        int ai; std::cin >> ai;
        if(!a.erase(ai)) a.insert(ai);
    }

    std::cout << a.size() << "\n";
    return 0;
}
