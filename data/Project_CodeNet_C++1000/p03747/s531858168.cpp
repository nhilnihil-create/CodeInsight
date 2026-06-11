#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100005;

int n, t, l;

int hou[maxn];

int main()
{
    scanf("%d%d%d", &n, &l, &t);
    int fromm = 0;
    for (int i = 1, x, fx; i <= n; ++i)
    {
        scanf("%d%d", &x, &fx);
        if (fx == 2)
        {
            hou[i] = x - t;
            (fromm -= (l - hou[i] - 1) / l) %= n;
            // cout << "hou = " << hou[i] << endl;
            ((hou[i] %= l) += l) %= l;
        }
        else
        {
            hou[i] = x + t;
            // cout << "hou = " << hou[i] << endl;
            (fromm += hou[i] / l) %= n;
            hou[i] %= l;
        }
    }
    (fromm += n) %= n;
    sort(hou + 1, hou + n + 1);
    // cout << "n = " << n << ' ' << fromm << endl;
    for (int i = fromm + 1; i <= n; ++i)
        printf("%d\n", hou[i]);
    // puts("");
    for (int i = 1; i <= fromm; ++i)
        printf("%d\n", hou[i]);
    return 0;
}
