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
    std::string s; std::cin >> s;

    std::vector<bool> v(26,0);
    for(int i=0; i<s.size(); i++){
        v[s[i]-'a'] = 1;
    }

    for(int i=0; i<26; i++){
        if(v[i]==0){
            std::cout << static_cast<char>('a'+i) << "\n";
            return 0;
        }
    }
    std::cout << "None" << "\n";
    return 0;
}