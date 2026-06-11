#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int t, a, b;
int main()
{
    cin >> t >> a >> b;
    if(a > b)   swap(a, b);
    if(a + t >= b)  cout << 0;
    else
        cout << b - a - t;
    return 0;
}
