#include <cstdio>

int x, a, b;

int abs(int y)
{
    if (y > 0) return y;
    else return -y;
}

void solve()
{
    if (abs(x-a) < abs(x-b)) printf("A\n");
    else printf("B\n");
}

int main()
{
    scanf("%d%d%d", &x, &a, &b);
    solve();
    return 0;
}