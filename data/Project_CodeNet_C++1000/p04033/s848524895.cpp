#include <iostream>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <iomanip>
#include <vector>
#include <functional>
#include <algorithm>
#include <cstdio>
#include <random>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#include <string.h>
#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    ll a, b;
    cin >> a >> b;
    if (a * b < 0)
    {
        cout << "Zero" << endl;
        return 0;
    }
    if (a + b > 0)
    {
        cout << "Positive" << endl;
    }
    else
    {
        if ((b - a + 1) % 2)
        {
            cout << "Negative" << endl;
        }
        else
        {
            cout << "Positive" << endl;
        }
    }
}