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
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main(){
    int a,b; std::cin >> a >> b;

    if(a>0){
        std::cout << "Positive" << "\n";
        return 0;
    }

    if(a<=0 && 0<=b){
        std::cout << "Zero" << "\n";
        return 0;
    }

    if(b<0){
        if(abs(a-b)%2){
            std::cout << "Positive" << "\n";
        }else{
            std::cout << "Negative" << "\n";
        }
        return 0;
    }
}