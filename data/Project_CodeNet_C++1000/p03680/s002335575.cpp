#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <cmath>
#include <cctype>
#include <map>
#include <set>

const int INT_INF = 1e9;
const long long LONG_INF = 1e18;
const long long MOD = 1e9 + 7;
const double PI = 3.14159265358979323846;

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<bool> f(n + 1, false);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int b = 1;
    f[1] = true;
    int count = 0;
    while (true)
    {
        if (b == 2)
        {
            cout << count << endl;
            return 0;
        }
        b = a[b];
        if (!f[b])
        {
            f[b] = true;
        }
        else
        {
            cout << -1 << endl;
            return 0;
        }
        count++;
    }
}