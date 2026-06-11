#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

unsigned int getdigit(unsigned long long int n)
{
    unsigned int d = 0;
    while(n != 0){
        n /= 10;
        d++;
    }
    return d;
}

int main()
{
    unsigned long long int n, a, b;
    cin >> n;

    for(a = floor(sqrt((double)n)); a > 0; a--){
        if(!(n % a)) break;
    }

    cout << getdigit((n/a)) << endl;
    return 0;
}