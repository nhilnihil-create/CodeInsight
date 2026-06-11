#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, l, t, a[100001], cnt;
int main(int argc, char const *argv[])
{
    scanf("%d%d%d", &n, &l, &t);
    for (int i = 1; i <= n; i++)
    {
        int op;
        scanf("%d%d", &a[i], &op);
        a[i] += op == 1 ? t : -t;
        cnt += a[i] / l;
        if (a[i] % l < 0)
        {
            cnt--;
        }
        a[i] = (a[i] % l + l) % l;
    }
    sort(a + 1, a + n + 1);
    cnt = (cnt % n + n) % n;
    for (int i = cnt + 1; i <= n; i++)
    {
        printf("%d\n", a[i]);
    }
    for (int i = 1; i <= cnt; i++)
    {
        printf("%d\n", a[i]);
    }
    return 0;
}