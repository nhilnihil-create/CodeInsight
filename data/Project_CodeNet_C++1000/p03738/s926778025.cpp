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
typedef pair<int, int> Pint;
typedef pair<ll, ll> Pll;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    string a, b;
    cin >> a >> b;
    if (a.size() > b.size())
    {
        cout << "GREATER" << endl;
        return 0;
    }
    if (a.size() < b.size())
    {
        cout << "LESS" << endl;
        return 0;
    }
    rep(0, i, a.size())
    {
        if (a.at(i) > b.at(i))
        {
            cout << "GREATER" << endl;
            return 0;
        }
        if (a.at(i) < b.at(i))
        {
            cout << "LESS" << endl;
            return 0;
        }
    }
    cout << "EQUAL" << endl;
}