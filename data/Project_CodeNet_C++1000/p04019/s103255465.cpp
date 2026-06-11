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
    string s;
    cin >> s;
    int N = s.size();
    int a = 0, b = 0, c = 0, d = 0;
    rep(0, i, N)
    {
        if (s.at(i) == 'N')
        {
            a = 1;
        }
        if (s.at(i) == 'W')
        {
            b = 1;
        }
        if (s.at(i) == 'S')
        {
            c = 1;
        }
        if (s.at(i) == 'E')
        {
            d = 1;
        }
    }
    if (a == c && b == d)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}