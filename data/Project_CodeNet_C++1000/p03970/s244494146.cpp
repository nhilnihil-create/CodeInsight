#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// 最大公約数
ll GCD(ll a, ll b)
{
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}

// 最小公倍数
ll LCM(ll a, ll b)
{
    ll g = GCD(a, b);
    return a / g * b;
}

int main()
{
    string in;
    cin >> in;
    int ret = 0;
    if (in[0] != 'C')
    {
        ret++;
    }
    if (in[1] != 'O')
    {
        ret++;
    }
    if (in[2] != 'D')
    {
        ret++;
    }
    if (in[3] != 'E')
    {
        ret++;
    }
    if (in[4] != 'F')
    {
        ret++;
    }
    if (in[5] != 'E')
    {
        ret++;
    }
    if (in[6] != 'S')
    {
        ret++;
    }
    if (in[7] != 'T')
    {
        ret++;
    }
    if (in[8] != 'I')
    {
        ret++;
    }
    if (in[9] != 'V')
    {
        ret++;
    }
    if (in[10] != 'A')
    {
        ret++;
    }
    if (in[11] != 'L')
    {
        ret++;
    }
    if (in[12] != '2')
    {
        ret++;
    }
    if (in[13] != '0')
    {
        ret++;
    }
    if (in[14] != '1')
    {
        ret++;
    }
    if (in[15] != '6')
    {
        ret++;
    }
    cout << ret << endl;
    return 0;
}