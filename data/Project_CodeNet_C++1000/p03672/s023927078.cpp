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
    string s;
    cin >> s;

    int len = s.length() / 2 - 1;
    while (true)
    {
        bool f = true;
        for (int i = 0; i < len; i++)
        {
            if (s[i] != s[i + len])
            {
                f = false;
                len--;
                break;
            }
        }
        if (f)
        {
            cout << (len * 2) << endl;
            return 0;
        }
    }
}