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
    std::string w;
    std::cin >> w;

    std::vector<bool> alphabet(26,0);
    rep(i,w.size()){
        int j = w[i] - 'a';
        alphabet[j] = alphabet[j] ^ 1;
    }

    rep(i,26){
        if(alphabet[i]){
            std::cout << "No" << "\n";
            return 0;
        }
    }
    std::cout << "Yes" << "\n";
    return 0;
}