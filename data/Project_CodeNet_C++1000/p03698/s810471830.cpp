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
    std::string s; std::cin >> s;
    for(int i=0; i<s.size()-1; i++){
        for(int j=i+1; j<s.size(); j++){
            if(s[j]==s[i]){
                std::cout << "no" << "\n";
                return 0;
            }
        }
    }
    std::cout << "yes" << "\n";
    return 0;
}
