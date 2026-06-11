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
    long long int a, b;
    cin >> a >> b;

    long long int ans = 0;
    if (a * b < 0) {
        ans++;
        a = -a;
    }
    else if (a > b) {
        if (a == 0 || b == 0) {
            ans++;
        }
        else {
            ans += 2;
        }
    }

    ans += abs(a - b);

    cout << ans << endl;
    return 0;
}