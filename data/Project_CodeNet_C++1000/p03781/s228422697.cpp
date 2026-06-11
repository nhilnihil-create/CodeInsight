#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>

int main(){
    int x;
    std::cin >> x;
    
    int t = 0;
    while (t * (t + 1) / 2 < x)
    {
        t++;
    }
    
    std::cout << t << std::endl;

    return 0;
}