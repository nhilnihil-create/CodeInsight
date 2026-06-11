#include <cmath>
#include <vector>
#include <map>
#include <functional>
#include <queue>
#include <iostream>
#include <string.h>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <cstdint>
#include <climits>
#include <unordered_set>
#include <sstream>

using namespace std;

#define ll long long int

int main()
{
    ll n;
    cin >> n;
    ll upper = sqrt(n * 2) + 1;
    ll prev = 0;
    ll diff = 0;
    ll result = 0;
    for(ll i = 1;i <= upper;i++)
    {
        ll current = (i + 1) * i / 2LL;
        if(prev <= n && current >= n)
        {
            diff = current - n;
            result = i;
            break;
        }
        prev = current;
    }
    for(ll i = 1;i <= result;i++)
    {
        if(i != diff)
        {
            cout << i << endl;
        }
    }
    return 0;
}
