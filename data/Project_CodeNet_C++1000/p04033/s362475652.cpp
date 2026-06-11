// https://atcoder.jp/contests/agc002/tasks/agc002_a
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <bitset>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define REP(i, n) for(size_t i = 0; i < (n); ++i)

int main()
{
    ll a, b;
    cin >> a >> b;
    if (a == 0 || b == 0 || (a < 0 && b > 0))
    {
        cout << "Zero" << endl;
        return 0;
    }

    if (a > 0)
    {
        cout << "Positive" << endl;
        return 0;
    }

    if (a < 0 && b < 0)
    {
        if ((b - a + 1) % 2 == 0)
        {
            cout << "Positive" << endl;
            return 0;
        }
        else
        {
            cout << "Negative" << endl;
            return 0;
        }
        
    }
    return 0;
}
