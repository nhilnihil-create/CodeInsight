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
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int state = 0;
    int ans = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (state == 0)
        {
            if (a[i] > a[i + 1])
            {
                state = -1;
            }
            else if (a[i] < a[i + 1])
            {
                state = 1;
            }
        }
        else if (state == 1)
        {
            if (a[i] > a[i + 1])
            {
                state = 0;
                ++ans;
            }
        }
        else
        {
            if (a[i] < a[i + 1])
            {
                state = 0;
                ++ans;
            }
        }
    }
    ++ans;
    printf("%d\n", ans);
    return 0;
}
