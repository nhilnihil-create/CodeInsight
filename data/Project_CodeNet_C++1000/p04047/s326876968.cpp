#include <bits/stdc++.h>
using namespace std;

const int Maxn = 205;

int n;
int a[Maxn];
int res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i++)
        scanf("%d", &a[i]);
    sort(a, a + 2 * n);
    for (int i = 0; i < n; i++)
        res += a[2 * i];
    printf("%d\n", res);
    return 0;
}
