#include <stdio.h>
#define all 100009

int red[all];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int num[n+1];
    for (int i = 1; i <= n; i++)
    {
        num[i] = 1;
        red[i] = 0;
    }
    red[1] = 1;
    int x, y;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &x, &y);
        if (red[x] == 1)
        {
            red[y] = 1; //表示一种可能性，只要管可能性增加，不要管减少，注意没有球的时候
        }
        num[x]--;
        num[y]++;
        if (num[x] == 0)
        {
            red[x] = 0;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (red[i] == 1)
        {
            ans++;
        }
    }
    printf("%d\n", ans);
}