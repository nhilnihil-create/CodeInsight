#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

int x;

int main()
{
    std::cin >> x;
    puts(x < 1200 ? "ABC" : "ARC");
    return 0;
}