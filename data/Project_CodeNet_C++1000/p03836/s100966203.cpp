#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
    int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
    for (int x = sx; x < tx; ++x)
    {
        cout << 'R';
    }
    for (int y = sy; y < ty; ++y)
    {
        cout << 'U';
    }
    for (int x = tx; x > sx; --x)
    {
        cout << 'L';
    }
    for (int y = ty; y > sy; --y)
    {
        cout << 'D';
    }
    cout << 'D';
    for (int x = sx; x < tx + 1; ++x)
    {
        cout << 'R';
    }
    for (int y = sy - 1; y < ty; ++y)
    {
        cout << 'U';
    }
    cout << 'L';
    cout << 'U';
    for (int x = tx; x > sx - 1; --x)
    {
        cout << 'L';
    }
    for (int y = ty + 1; y > sy; --y)
    {
        cout << 'D';
    }
    cout << 'R' << endl;
}