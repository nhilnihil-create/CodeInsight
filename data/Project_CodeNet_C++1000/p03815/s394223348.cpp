#include <iostream>
#include <string>
#include <algorithm>
#include<cmath> 

int main()
{

    long long x;
    std::cin >> x;

    long long div = x / 11;
    long long mod = x % 11;
    long long ans1 = 2 * div, ans2 = 2*div;

    if(mod) {
    if(mod > 5) {
        ans1 += 2;
    } else  {
        ans1++;
    }

    if(mod > 6) {
        ans2 += 2;
    }
    else
    {
        ans2++;
    }
    }

    std::cout << std::min(ans1, ans2) << "\n";
}