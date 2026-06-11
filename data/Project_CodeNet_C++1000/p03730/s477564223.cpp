#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <math.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    string ans = "NO";
    vector<int> state(b, 0);
    int i = 0;
    while (true)
    {
        i += a;
        int mod = i % b;
        if (mod == c)
        {
            ans = "YES";
            break;
        }
        ++state[mod];
        if (state[mod] == 2)
        {
            break;
        }
    }
    cout << ans << endl;
}