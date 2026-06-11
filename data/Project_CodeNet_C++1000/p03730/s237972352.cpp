
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>
#include <cstdint>
#include <iomanip>
using ll = long long;

int main(){
    ll A,B,C; std::cin>>A>>B>>C;
    //aA=bB+Cとなるa,bが存在するか
    for(int a=1; a<B+1; ++a){
        if(a*A%B==C){
            std::cout << "YES";
            return 0;
        }
    }
    std::cout << "NO";
    return 0;
}
