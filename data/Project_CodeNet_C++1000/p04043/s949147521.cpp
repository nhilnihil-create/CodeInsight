#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

int main(void){
    int a, b, c;
    std::cin >> a >> b >> c;
    if(a == 5 && b == 5 && c == 7) std::cout << "YES" << std::endl;
    else if(a == 5 && b == 7 && c == 5) std::cout << "YES" << std::endl;
    else if(a == 7 && b == 5 && c == 5) std::cout << "YES" << std::endl;
    else std::cout << "NO" << std::endl;

    return 0;
}