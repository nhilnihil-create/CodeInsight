#include <algorithm>
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
const double PI = 3.14159265359;

int main()
{
    int a, b; cin >> a >> b;
    if (a <= 0 && 0 <= b)
    {
        cout << "Zero\n";
    }
    else if(0 < a)
    {
        cout << "Positive\n";
    }
    else
    {
        if ((b - a + 1) % 2 == 1)
        {
            cout << "Negative\n";
        }
        else
        {
            cout << "Positive\n";
        }
    }
}
