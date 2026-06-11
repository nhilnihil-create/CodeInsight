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
    int ans = 0;
    for (int i = 1; i < s.length(); i++) {
        if (s[i-1] != s[i]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}