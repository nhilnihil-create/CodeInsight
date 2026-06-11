#include <cstdio>

int n, a;

void solve()
{
    int b = n*n - a;
    printf("%d\n", b);
}

int main()
{
    scanf("%d%d", &n, &a);

    solve();

    return 0;
}