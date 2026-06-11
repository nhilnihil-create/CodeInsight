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
    std::string a,b;
    std::cin >> a >> b;
    if(a.size()>b.size()){
        std::cout << "GREATER" << "\n";
        return 0;
    }

    if(a.size()==b.size()){
        for(int i=0; i<a.size(); i++){
            if(a[i]>b[i]){
                std::cout << "GREATER" << "\n";
                return 0;
            }
            if(a[i]<b[i]){
                std::cout << "LESS" << "\n";
                return 0;
            }
        }
        std::cout << "EQUAL" << "\n";
        return 0;
    }

    if(a.size()<b.size()){
        std::cout << "LESS" << "\n";
        return 0;
    }
}