#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n, L;
int a[Maxn];

int main()
{
    scanf("%d %d", &n, &L);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i + 1 <= n; i++) if (a[i] + a[i + 1] >= L) {
        printf("Possible\n");
        for (int j = 1; j < i; j++)
            printf("%d\n", j);
        for (int j = n - 1; j > i; j--)
            printf("%d\n", j);
        printf("%d\n", i);
        return 0;
    }
    printf("Impossible\n");
    return 0;
}
