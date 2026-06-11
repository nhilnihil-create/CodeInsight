#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;

int n, x;
int res[Maxn];
int pnt;

int main()
{
    scanf("%d %d", &n, &x);
    n = 2 * n - 1;
    if (x == 1 || x == n) printf("No\n");
    else {
        printf("Yes\n");
        int mid = (n + 1) / 2;
        if (x > mid) {
            int l = mid, r = x - 1;
            for (int i = 1; i < l; i++)
                res[pnt++] = i;
            res[pnt++] = x;
            for (int i = x + 1; i <= n; i++)
                res[pnt++] = i;
            for (int i = l; i <= r; i++)
                res[pnt++] = i;
        } else if (x == mid)
            for (int i = 1; i <= n; i++)
                res[pnt++] = i;
        else {
            int l = x + 1, r = mid;
            pnt = n - 1;
            for (int i = n; i > r; i--)
                res[pnt--] = i;
            res[pnt--] = x;
            for (int i = x - 1; i > 0; i--)
                res[pnt--] = i;
            for (int i = r; i >= l; i--)
                res[pnt--] = i;
        }
        for (int i = 0; i < n; i++)
            printf("%d\n", res[i]);
    }
    return 0;
}
