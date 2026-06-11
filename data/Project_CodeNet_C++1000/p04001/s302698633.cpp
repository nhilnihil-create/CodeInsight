#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>

long sum(std::string& S, int v){
    std::vector<long> d;
    //std::cout << "--" << v << "--" << std::endl;
    std::string s = "";
    s += S.at(0);
    for(int i = 1; i < S.size(); i++){
        if(v&0x01 == 1){
            d.push_back(std::stol(s));
            s = S.at(i);
        }else{
            s += S.at(i);
        }
        v = v >> 1;
    }
    d.push_back(std::stol(s));
    long ans = 0;
    for(int i = 0; i < d.size(); i++){
        //std::cout << d.at(i) << std::endl;
        ans += d.at(i);
    }
    return ans;
}

int main(int argc, char **argv)
{
    std::string S;
    std::cin >> S;

    int bits = std::pow(2, S.size()-1);
    //std::cout << bits << std::endl;

    long ans = 0;
    for(int i = 0; i < bits; i++){
        ans += sum(S, i);
    }
    
    std::cout << ans << std::endl;
}
