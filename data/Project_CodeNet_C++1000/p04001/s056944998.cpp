#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

int main(int argc, const char * argv[]) {

    std::string S;
    std::cin >> S;

    unsigned long size = S.size();
    if(size == 1) {
        std::cout << S;
        return 0;
    }

    long long count = std::pow(2, size - 1);
    long long sum = 0;
    for(unsigned long i=0; i<count; i++) {
        std::string formula;
        formula.push_back(S[0]);
        for(unsigned long j=0; j<=size-2; j++) {
            if(i&(1<<j)) {
                formula.push_back('+');
            }
//            std::cout << j <<std::endl;
            formula.push_back(S[j+1]);
        }

        std::istringstream strm(formula);
        std::string tmp;
        unsigned long ans = 0;
        while(getline(strm, tmp, '+')) {
            ans += std::stoll(tmp);
        }
        sum += ans;

//        std::cout << formula << "=" << ans << std::endl;
    }

    std::cout << sum;

    return 0;
}
