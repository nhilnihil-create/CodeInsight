#include <iostream> 
#include <stdlib.h> 
#include <string.h> 
#include <string> 
#include <sstream>
#include <cstring> 
#include<cmath>
using namespace std;
int main()
{
    long long x; cin >> x;
    long long y = 1;
    for (int i = 1; i <= x; i++) {
        y *= i;
        y %= 1000000007;
    }
    cout <<y;
    return 0;
}