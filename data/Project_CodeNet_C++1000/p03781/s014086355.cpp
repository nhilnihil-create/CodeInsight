#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <numeric>
#include <set>
#include <list>
#include <bitset>
#include <cstdlib>
using namespace std;

int main()
{
    int X;
    cin >> X;
    int step = 1;
    while ((step * (step + 1)) / 2 < X)
    {
        step++;
    }
    cout << step << endl;
    return 0;
}