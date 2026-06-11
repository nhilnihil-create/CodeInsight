#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    scanf("%d", &n);
    string s, t;
    cin >> s >> t;
    int ans = n + n;
    for (int i = 1; i <= n; ++i)
    {
        bool ok = true;
        for (int k = 0; k < i; ++k)
        {
            if (s[n - i + k] != t[k])
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            ans = (min)(ans, n + n - i);
        }
    }
    cout << ans << endl;
    return 0;
}
