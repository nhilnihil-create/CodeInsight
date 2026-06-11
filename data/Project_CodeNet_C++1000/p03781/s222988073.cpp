#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <cstdio>
#include <iomanip>
#include <utility>

using namespace std;
typedef long long int ll;

#define SP(x) setprecision((int)x)
#define ALL(v) v.begin(),v.end()

int main(int argc, char const *argv[])
{
    ll x;
    cin >> x;

    ll k = 0;
    while (1)
    {
        k++;
        if (k * (k + 1) / 2 >= x)
        {
            break;
        }
    }

    cout << k << endl;
}