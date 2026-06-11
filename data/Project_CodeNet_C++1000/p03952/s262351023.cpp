#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <queue>
#include <stack>
#include <bitset>
#include <set>
#include <chrono>
#include <string>
#include <assert.h>

using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    n = 2 * n - 1;

    if (x == 1 || x == n)
    {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;

    vector<int> ans(n);
    vector<bool> used(n + 1);

    if (n == 3)
    {
        ans[0] = 1, ans[1] = 2, ans[2] = 3;
    }
    else
    {
        if (x == 2)
        {
            ans[n / 2 - 2] = 4;
            ans[n / 2 - 1] = 1;
            ans[n / 2] = x;
            ans[n / 2 + 1] = 3;
        }
        else
        {
            ans[n / 2 - 2] = x - 2;
            ans[n / 2 - 1] = x + 1;
            ans[n / 2] = x;
            ans[n / 2 + 1] = x - 1;
        }

        for (int i = -2; i <= +1; ++i)
            used[ans[n / 2 + i]] = true;

        for (int i = 0, j = 1; i < n; ++i)
        {
            if (ans[i])
                continue;

            while (used[j])
                ++j;

            ans[i] = j++;
        }
    }

    for (auto y : ans)
        cout << y << endl;

    return 0;
}